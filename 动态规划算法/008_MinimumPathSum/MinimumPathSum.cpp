/* TITLE: Minimum Path Sum
 *		Given a m x n grid filled with non-negative numbers,
 *		find a path from top left to bottom right which minimizes
 *		the sum of all numbers along its path.
 *		Note: You can only move either down or right at any point in time.
 * TIME:2015-5-12
 * FROM:leetcode
 * TYPE:DP
 * AUTHOR:PengSc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 迭代法实现的动态规划算法
 * 性能：时间复杂度O(m*n), 空间复杂度O(m*n)
 */
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid.at(0).size();
		if (n == 0)
			return 0;
		else if (m == 1 && n == 1) //1 x 1
			return grid[0][0];
		else {
			int **res = new int*[m]; //中每一个值存储从grid[0][0]当前点最小和
			int tmp;
			for (int i = 0; i < m; i++)
				res[i] = new int[n];
			for (int i = 0, tmp = 0; i < m; i++){ //第0列初值
				tmp += grid[i][0];
				res[i][0] = tmp;
			}
			for (int j = 0, tmp = 0; j < n; j++){ //第0行初值
				tmp += grid[0][j];
				res[0][j] = tmp;
			}

			for (int i = 1; i < m; i++){
				for (int j = 1; j < n; j++){
					res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
				}
			}
			return res[m - 1][n - 1];
		}
	}
};

/* 以下是大牛用C指针实现的代码， 改变了grid中的值 */
int minPathSum(int **grid, int nRows, int nCols) {
	int*pc, *pu, *pl, *pe, **ppc, **ppu, **ppe;
	for (ppu = grid, ppc = ppu + 1, ppe = ppu + nRows; ppc < ppe; ppu = ppc, ++ppc){
		**ppc += **ppu;
	}
	for (pl = grid[0], pc = pl + 1, pe = pl + nCols; pc < pe; pl = pc, ++pc){
		*pc += *pl;
	}
	for (ppu = grid, ppc = ppu + 1, ppe = ppu + nRows; ppc < ppe; ppu = ppc, ++ppc){
		for (pl = ppc[0], pu = ppu[0] + 1, pc = pl + 1, pe = pl + nCols; pc < pe; pl = pc, ++pc, ++pu){
			*pc += (*pl <= *pu ? *pl : *pu);
		}
	}
	return grid[nRows - 1][nCols - 1];
}

int main()
{
	Solution s;
	vector<vector<int>> grid;
	vector<int> v;
	int m = 3, n = 1;
	int k = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			v.push_back(k++);
		grid.push_back(v);
		v.clear();
	}
//	grid[2][0] = 0;
	cout << s.minPathSum(grid) << endl;
	system("pause");
}