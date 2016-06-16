/* TITLE: Word Search 
 *		Given a 2D board and a word, find if the word exists in the grid. 
 *		The word can be constructed from letters of sequentially adjacent cell,
 *		where "adjacent" cells are those horizontally or vertically neighboring.
 *		The same letter cell may not be used more than once. 
 *		For example,
 *		Given board = 
 *		[
		  ["ABCE"],
		  ["SFCS"],
		  ["ADEE"]
		]
 *		word = "ABCCED", -> returns true,
 *		word = "SEE", -> returns true,
 *		word = "ABCB", -> returns false.
 *
 * TIME:2015-5-18
 * TYPE:backtrace(回溯)
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 递归实现，时间复杂度O(m*n)，空间复杂度O(m*n)，均为数组长度规模
 */
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board[0].size();
		if (m == 0 || word.size() == 0)
			return false;
		vector<bool> visited(m*n, false);
		bool res = false;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == word[0]){
					res = exist(board, i, j, word, visited);
					if (res)
						return res;
				}
			}
		}
		return res;
	}
private:
	bool exist(vector<vector<char>> &board, int i, int j, string subWord, vector<bool> &visited)
	{
		if (subWord.size() == 0)
			return true;
		int m = board.size(), n = board[0].size();
		bool res = false;
		if (check(board, i, j, visited) && board[i][j] == subWord[0]){
			visited[i*n + j] = true; //先标记
			res = exist(board, i, j + 1, subWord.substr(1), visited); //right
			if (!res)
				res = exist(board, i + 1, j, subWord.substr(1), visited); //down
			if (!res)
				res = exist(board, i, j - 1, subWord.substr(1), visited); //left
			if (!res)
				res = exist(board, i - 1, j, subWord.substr(1), visited); //up
			if (!res) //当前点不是单词中的一个点，取消标记以便再次访问
				visited[i*n + j] = false;
		}
		return res;
	}
	/* 检查访问的点i,j是否合法及是否被访问过，它决定能否访问它 */
	bool check(vector<vector<char>>&board, int i, int j, vector<bool> &visited)
	{
		int m = board.size(), n = board[0].size();
		if (i >= 0 && i < m && j >= 0 && j < n && !visited[i*n + j])
			return true;
		return false;
	}
};

int main()
{
	//vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A','D','E','E' } };
	Solution sl;
	//string word = "SEE";
	//string word = "ABCCED";
	//string word = "ABCESEEDAS";


	vector<vector<char>> board = { { 'C', 'A', 'A' }, { 'A', 'A', 'A' }, { 'B','C','D' } };
	string word = "AABC";

	//vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'E', 'S' }, { 'A', 'D', 'E', 'E' } };
	//string word = "ABCEFSADEES";//"ABCEFSADEESE";

	//vector<vector<char>>board = { { 'a', 'a' } };
	//string word = "aaa";
	cout << sl.exist(board, word) << endl;
	system("pause");
}