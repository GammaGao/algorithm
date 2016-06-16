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

/* DFS: 使用深度优先搜索算法，访问相邻节点之前优先访问其孙子节点。
 * 思路：由于想找出所有islands个数，在访问时，必须把相邻访问的点变成'0'，那么islands的个数就是'1'的个数，这样问题会逐步减化
 *		倘若不作改变，那么每次访问到‘1’都得对四周的情况做判断，及其复杂。
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
			grid[row][col] = '0'; //访问过的点变成'0'，其实变成'v'似乎更容易接受，但为了代码简洁性
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