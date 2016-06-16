/* @TITLE: N-Queens
*		The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
*		Given an integer n, return all distinct solutions to the n-queens puzzle.
*		Each solution contains a distinct board configuration of the n-queens' placement,
*		where 'Q' and '.' both indicate a queen and an empty space respectively.
*		For example,
*		There exist two distinct solutions to the 4-queens puzzle:
		[
		[".Q..",  // Solution 1
		"...Q",
		"Q...",
		"..Q."],

		["..Q.",  // Solution 2
		"Q...",
		"...Q",
		".Q.."]
		]
* @NOTE:规则是任意两个皇后不能处在同一列或同一行或同一对角线上（指处在斜率为1或-1上）
* @TIME:2015-5-25
* @TYPE:backtracking
* @FROM:leetcode
* @AUTHOR:PengSc
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> res; //存放结果
		vector<string> board; //棋盘状态
		vector<pos> occupied; //每一行的皇后位置
		string s(n, '.');
		for (int i = 0; i < n; i++){
			board.push_back(s);
		}
		solveNQueens(res, occupied, board, n, 0);
		return res;
	}
private:
	struct pos{
		int row;
		int col;
	};

	void solveNQueens(vector<vector<string>> &res, vector<pos> &occupied, vector<string> &board, int n, int row)
	{
		struct pos curr;
		if (row == n){
			res.push_back(board);
			return;
		}
		for (int j = 0; j < n; j++){
			if (isValidPlace(occupied, n, row, j)){
				curr.row = row; curr.col = j;
				occupied.push_back(curr);
				board[row][j] = 'Q'; //放置皇后
				solveNQueens(res, occupied, board, n, row+1);
				occupied.pop_back(); 
				board[row][j] = '.'; //还原
			}
		}
	}

	/* 判断皇后位置是否有效 */
	bool isValidPlace(vector<pos> &occupied, int n, int row, int col)
	{
		if (row < 0 || row >= n || col < 0 || col >= n) //越界
			return false;
		for (int i = 0; i < occupied.size(); i++){
			if (row - occupied[i].row ==  col - occupied[i].col || //斜率1
				occupied[i].col == col || //同一列，之所以没对同一行进行判断是没必要，因为是逐行处理，不会处在同一行
				row - occupied[i].row == occupied[i].col - col) //斜率-1
				return false;
		}
		return true;
	}
};

class Solution_1 {
public:
	std::vector<std::vector<std::string> > solveNQueens(int n) {
		std::vector<std::vector<std::string> > res;
		size = n;
		std::vector<std::string> nQueens(size, std::string(size, '.'));
		solveNQueens(res, nQueens, 0);
		return res;
	}
private:
	int size;
	void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row) {
		if (row == size) {
			res.push_back(nQueens);
			return;
		}
		for (int col = 0; col != size; ++col)
			if (isValid(nQueens, row, col)) {
				nQueens[row][col] = 'Q';
				solveNQueens(res, nQueens, row + 1);
				nQueens[row][col] = '.';
			}
	}
	bool isValid(std::vector<std::string> &nQueens, int row, int col) {
		for (int i = 0; i != row; ++i)
			if (nQueens[i][col] == 'Q')
				return false;
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
			if (nQueens[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = col + 1; i >= 0 && j < size; --i, ++j)
			if (nQueens[i][j] == 'Q')
				return false;
		return true;
	}
};

int main()
{
	Solution sl;
	vector<vector<string>> res;
	res = sl.solveNQueens(8);
	cout << res.size() << endl;
	//for (int i = 0; i < res.size(); i++){
	//	for (int j = 0; j < res[i].size(); j++)
	//		cout << res[i][j] << endl;
	//	cout << endl << endl;
	//}
	system("pause");
}