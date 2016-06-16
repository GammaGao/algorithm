/* @TITLE: N-QueensII
 *		The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
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
 *		Now, instead outputting board configurations, return the total number of distinct solutions.
 * @NOTE:���������������ʺ��ܴ���ͬһ�л�ͬһ�л�ͬһ�Խ����ϣ�ָ����б��Ϊ1��-1�ϣ�
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
	int totalNQueens(int n) {
		int res = 0;
		vector<string> board; //����״̬
		vector<pos> occupied; //ÿһ�еĻʺ�λ��
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

	void solveNQueens(int &res, vector<pos> &occupied, vector<string> &board, int n, int row)
	{
		struct pos curr;
		if (row == n){
			res++;
			return;
		}
		for (int j = 0; j < n; j++){
			if (isValidPlace(occupied, n, row, j)){
				curr.row = row; curr.col = j;
				occupied.push_back(curr);
				board[row][j] = 'Q'; //���ûʺ�
				solveNQueens(res, occupied, board, n, row + 1);
				occupied.pop_back();
				board[row][j] = '.'; //��ԭ
			}
		}
	}

	/* �жϻʺ�λ���Ƿ���Ч */
	bool isValidPlace(vector<pos> &occupied, int n, int row, int col)
	{
		if (row < 0 || row >= n || col < 0 || col >= n) //Խ��
			return false;
		for (int i = 0; i < occupied.size(); i++){
			if (row - occupied[i].row == col - occupied[i].col || //б��1
				occupied[i].col == col || //ͬһ�У�֮����û��ͬһ�н����ж���û��Ҫ����Ϊ�����д������ᴦ��ͬһ��
				row - occupied[i].row == occupied[i].col - col) //б��-1
				return false;
		}
		return true;
	}
};

int main()
{
	Solution sl;
	int res;
	res = sl.totalNQueens(8);
	cout << res << endl;
	//for (int i = 0; i < res.size(); i++){
	//	for (int j = 0; j < res[i].size(); j++)
	//		cout << res[i][j] << endl;
	//	cout << endl << endl;
	//}
	system("pause");
}