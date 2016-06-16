/* @TITLE: Number of Islands
 *		Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 *		An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 *		You may assume all four edges of the grid are all surrounded by water.
 *		Example 1:
		11110
		11010
		11000
		00000
 *		Answer: 1
 *
 *		Example 2:
		11000
		11000
		00100
		00011
 * 		Answer: 3
 *
 * @TIME:2015-6-9
 * @TYPE:DFS/BFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* DFS: ʹ��������������㷨���������ڽڵ�֮ǰ���ȷ��������ӽڵ㡣
 * ˼·���������ҳ�����islands�������ڷ���ʱ����������ڷ��ʵĵ���'0'����ôislands�ĸ�������'1'�ĸ���������������𲽼���
 *		���������ı䣬��ôÿ�η��ʵ���1�����ö����ܵ�������жϣ����临�ӡ�
 */
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;
		int num = 0;
		int m = grid.size();
		int n = grid.at(0).size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] != '1') //'0'
					continue;
				num++;
				dfs(grid, i, j);
			}
		}
		return num;
	}
private:
	void dfs(vector<vector<char>> &grid, int row, int col)
	{
		if (isValidNode(grid, row, col) && grid[row][col] == '1'){
			grid[row][col] = '0'; //���ʹ��ĵ���'0'����ʵ���'v'�ƺ������׽��ܣ���Ϊ�˴�������
			dfs(grid, row, col + 1);
			dfs(grid, row, col - 1);
			dfs(grid, row + 1, col);
			dfs(grid, row - 1, col);
		}
	}
	bool isValidNode(vector<vector<char>> &grid, int i, int j)
	{
		int m = grid.size();
		int n = grid.at(0).size();
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'v')
			return false;
		return true;
	}
};

int main()
{
	Solution sl;
	//vector<vector<char>> grid= { {'1','1','1','1','0' }, 
	//							{ '1','1','0','1','0' },
	//							{ '1','1','0','0','0' },
	//							{ '0','0','0','0','0' } };

	vector<vector<char>> grid = { { '1', '1', '0', '0', '0' },
								  { '1', '1', '0', '0', '0' },
								  { '0', '0', '1', '0', '0' },
								  { '0', '0', '0', '1', '1' } };
	cout << sl.numIslands(grid) << endl;
	system("pause");
}