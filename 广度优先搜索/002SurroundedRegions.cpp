/* @TITLE: Surrounded Regions
 *		Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *		A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *		For example,
		X X X X
		X O O X
		X X O X
		X O X X
 *		After running your function, the board should be:
		X X X X
		X X X X
		X X X X
		X O X X
 *
 * @TIME:2015-6-10
 * @TYPE:BFS/DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 * 难度系数Hard模式
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 思路解析：题目要求是找出被'X'保围的'O'，把它换成到'X'，常规思路是找出所有O, 再判断它们是不是满足被X包围，这么做比较复杂。
 *		反向思路，先去处理边界上的'O'，让它及所有与它相邻的节点变成'-'(中间状态)（DFS/BFS均可以），那么剩余的O必定是被X包围的。
 *		将它变成'X'，再将'-'还原成'O'
 */
/* BFS: 广度优先算法，在处理当前节点的子节点的孙子节点前，先去处理当前节点的相邻节点。
 */
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) //其实如果size()<3，均可以直接返回
			return;
		int m = board.size();
		int n = board.at(0).size();
		queue<vector<int>> coordinateQueue; //存放边界上'O'点坐标及与之相邻的'O'的坐标队列
		vector<int> coordinate; //坐标

		for (int i = 0; i < m; i++){ //左边界
			if (board[i][0] == 'O'){
				coordinate.push_back(i);
				coordinate.push_back(0);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[i][0] = '-';
			}
			if (board[i][n - 1] == 'O'){ //右边界
				coordinate.push_back(i);
				coordinate.push_back(n-1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[i][n - 1] = '-';
			}
		}
		for (int j = 0; j < n; j++){ //上边界
			if (board[0][j] == 'O'){
				coordinate.push_back(0);
				coordinate.push_back(j);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[0][j] = '-';
			}
			if (board[m - 1][j] == 'O'){ //下边界
				coordinate.push_back(m-1);
				coordinate.push_back(j);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[m - 1][j] = '-';
			}
		}

		//将边界上的'O'及与之相邻的'O'变成中间状态'-'
		while (!coordinateQueue.empty()){ //BFS, 没有递归
			vector<int> curr = coordinateQueue.front();
			coordinateQueue.pop();
			if (isValid(board, curr.at(0) - 1, curr.at(1)) && board[curr.at(0) - 1][curr.at(1)] == 'O'){
				coordinate.push_back(curr.at(0) - 1);
				coordinate.push_back(curr.at(1));
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0) - 1][curr.at(1)] = '-'; //向上
			}
			if (isValid(board, curr.at(0) + 1, curr.at(1)) && board[curr.at(0) + 1][curr.at(1)] == 'O'){
				coordinate.push_back(curr.at(0) + 1);
				coordinate.push_back(curr.at(1));
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0) + 1][curr.at(1)] = '-'; //向下
			}
			if (isValid(board, curr.at(0), curr.at(1) - 1) && board[curr.at(0)][curr.at(1) - 1] == 'O'){
				coordinate.push_back(curr.at(0));
				coordinate.push_back(curr.at(1) - 1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0)][curr.at(1) - 1] = '-'; //向左
			}
			if (isValid(board, curr.at(0), curr.at(1) + 1) && board[curr.at(0)][curr.at(1) + 1] == 'O'){
				coordinate.push_back(curr.at(0));
				coordinate.push_back(curr.at(1) + 1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0)][curr.at(1) + 1] = '-'; //向右
			}
		}

		//将剩余的'O'变成'X'； 中间状态'-'还原成'O'
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '-')
					board[i][j] = 'O';
			}
		}
	}
private:
	//判断访问是否越界
	bool isValid(vector<vector<char>> &board, int row, int col)
	{
		int m = board.size();
		int n = board.at(0).size();
		if (row < 0 || row >= m || col < 0 || col >= n)
			return false;
		return true;
	}
};

/* DFS: 深度优先搜索算法， 优先处理当前节点的子节点的孙子节点，而不去优先处理当前节点的相邻节点。
 * 性能: 时间性能不如BFS, DFS时间复杂度O(n!)
 * 思路同上，只是使用的DFS
 */
class Solution_1 {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;
		int m = board.size();
		int n = board.at(0).size();

		for (int i = 0; i < m; i++){
			if (board[i][0] == 'O')
				dfs(board, i, 0);
			if (board[i][n - 1] == 'O')
				dfs(board, i, n-1);
		}
		for (int j = 0; j < n; j++){
			if (board[0][j] == 'O')
				dfs(board, 0, j);
			if (board[m - 1][j] == 'O')
				dfs(board, m - 1, j);
		}
		for (int i = 1; i < m-1; i++){
			for (int j = 1; j < n-1; j++){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == '-')
					board[i][j] = 'O';
			}
		}
	}
private:
	void dfs(vector<vector<char>> &board, int row, int col)
	{
		if (isValid(board, row, col) && board[row][col] == 'O'){
			board[row][col] = '-'; //已经被访问
			dfs(board, row, col - 1);
			dfs(board, row, col + 1);
			dfs(board, row - 1, col);
			dfs(board, row + 1, col);
			//board[row][col] = 'O';
		}
	}
	bool isValid(vector<vector<char>> &board, int row, int col)
	{
		int m = board.size();
		int n = board.at(0).size();
		if (row < 0 || row >= m || col < 0 || col >= n)
			return false;
		return true;
	}
};



int main()
{
	Solution sl;
	//vector<vector<char>> board= { {'X', 'X', 'X', 'X'},
	//							  {'X', 'O', 'O', 'X'},
	//							  {'X', 'X', 'O', 'X'},
	//							  {'X', 'O', 'X', 'X'} };

	//vector<vector<char>> board= { {'X', 'X', 'X'},
	//							  {'X', 'O', 'X'},
	//							  {'X', 'X', 'X'} };

	vector<vector<char>> board = { { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O' },
									{ 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O' },
									{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
									{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' } };
	sl.solve(board);
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.at(0).size(); j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	system("pause");
}