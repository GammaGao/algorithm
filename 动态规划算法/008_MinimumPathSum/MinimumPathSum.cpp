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

/* ������ʵ�ֵĶ�̬�滮�㷨
 * ���ܣ�ʱ�临�Ӷ�O(m*n), �ռ临�Ӷ�O(m*n)
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
			int **res = new int*[m]; //��ÿһ��ֵ�洢��grid[0][0]��ǰ����С��
			int tmp;
			for (int i = 0; i < m; i++)
				res[i] = new int[n];
			for (int i = 0, tmp = 0; i < m; i++){ //��0�г�ֵ
				tmp += grid[i][0];
				res[i][0] = tmp;
			}
			for (int j = 0, tmp = 0; j < n; j++){ //��0�г�ֵ
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

/* �����Ǵ�ţ��Cָ��ʵ�ֵĴ��룬 �ı���grid�е�ֵ */
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