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
 * �Ѷ�ϵ��Hardģʽ
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* ˼·��������ĿҪ�����ҳ���'X'��Χ��'O'���������ɵ�'X'������˼·���ҳ�����O, ���ж������ǲ������㱻X��Χ����ô���Ƚϸ��ӡ�
 *		����˼·����ȥ����߽��ϵ�'O'�������������������ڵĽڵ���'-'(�м�״̬)��DFS/BFS�����ԣ�����ôʣ���O�ض��Ǳ�X��Χ�ġ�
 *		�������'X'���ٽ�'-'��ԭ��'O'
 */
/* BFS: ��������㷨���ڴ���ǰ�ڵ���ӽڵ�����ӽڵ�ǰ����ȥ����ǰ�ڵ�����ڽڵ㡣
 */
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) //��ʵ���size()<3��������ֱ�ӷ���
			return;
		int m = board.size();
		int n = board.at(0).size();
		queue<vector<int>> coordinateQueue; //��ű߽���'O'�����꼰��֮���ڵ�'O'���������
		vector<int> coordinate; //����

		for (int i = 0; i < m; i++){ //��߽�
			if (board[i][0] == 'O'){
				coordinate.push_back(i);
				coordinate.push_back(0);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[i][0] = '-';
			}
			if (board[i][n - 1] == 'O'){ //�ұ߽�
				coordinate.push_back(i);
				coordinate.push_back(n-1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[i][n - 1] = '-';
			}
		}
		for (int j = 0; j < n; j++){ //�ϱ߽�
			if (board[0][j] == 'O'){
				coordinate.push_back(0);
				coordinate.push_back(j);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[0][j] = '-';
			}
			if (board[m - 1][j] == 'O'){ //�±߽�
				coordinate.push_back(m-1);
				coordinate.push_back(j);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[m - 1][j] = '-';
			}
		}

		//���߽��ϵ�'O'����֮���ڵ�'O'����м�״̬'-'
		while (!coordinateQueue.empty()){ //BFS, û�еݹ�
			vector<int> curr = coordinateQueue.front();
			coordinateQueue.pop();
			if (isValid(board, curr.at(0) - 1, curr.at(1)) && board[curr.at(0) - 1][curr.at(1)] == 'O'){
				coordinate.push_back(curr.at(0) - 1);
				coordinate.push_back(curr.at(1));
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0) - 1][curr.at(1)] = '-'; //����
			}
			if (isValid(board, curr.at(0) + 1, curr.at(1)) && board[curr.at(0) + 1][curr.at(1)] == 'O'){
				coordinate.push_back(curr.at(0) + 1);
				coordinate.push_back(curr.at(1));
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0) + 1][curr.at(1)] = '-'; //����
			}
			if (isValid(board, curr.at(0), curr.at(1) - 1) && board[curr.at(0)][curr.at(1) - 1] == 'O'){
				coordinate.push_back(curr.at(0));
				coordinate.push_back(curr.at(1) - 1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0)][curr.at(1) - 1] = '-'; //����
			}
			if (isValid(board, curr.at(0), curr.at(1) + 1) && board[curr.at(0)][curr.at(1) + 1] == 'O'){
				coordinate.push_back(curr.at(0));
				coordinate.push_back(curr.at(1) + 1);
				coordinateQueue.push(coordinate);
				coordinate.clear();
				board[curr.at(0)][curr.at(1) + 1] = '-'; //����
			}
		}

		//��ʣ���'O'���'X'�� �м�״̬'-'��ԭ��'O'
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
	//�жϷ����Ƿ�Խ��
	bool isValid(vector<vector<char>> &board, int row, int col)
	{
		int m = board.size();
		int n = board.at(0).size();
		if (row < 0 || row >= m || col < 0 || col >= n)
			return false;
		return true;
	}
};

/* DFS: ������������㷨�� ���ȴ���ǰ�ڵ���ӽڵ�����ӽڵ㣬����ȥ���ȴ���ǰ�ڵ�����ڽڵ㡣
 * ����: ʱ�����ܲ���BFS, DFSʱ�临�Ӷ�O(n!)
 * ˼·ͬ�ϣ�ֻ��ʹ�õ�DFS
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
			board[row][col] = '-'; //�Ѿ�������
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