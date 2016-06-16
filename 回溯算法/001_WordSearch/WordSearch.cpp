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
 * TYPE:backtrace(����)
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* �ݹ�ʵ�֣�ʱ�临�Ӷ�O(m*n)���ռ临�Ӷ�O(m*n)����Ϊ���鳤�ȹ�ģ
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
			visited[i*n + j] = true; //�ȱ��
			res = exist(board, i, j + 1, subWord.substr(1), visited); //right
			if (!res)
				res = exist(board, i + 1, j, subWord.substr(1), visited); //down
			if (!res)
				res = exist(board, i, j - 1, subWord.substr(1), visited); //left
			if (!res)
				res = exist(board, i - 1, j, subWord.substr(1), visited); //up
			if (!res) //��ǰ�㲻�ǵ����е�һ���㣬ȡ������Ա��ٴη���
				visited[i*n + j] = false;
		}
		return res;
	}
	/* �����ʵĵ�i,j�Ƿ�Ϸ����Ƿ񱻷��ʹ����������ܷ������ */
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