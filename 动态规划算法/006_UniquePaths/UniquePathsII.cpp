/* TITLE: Follow up for "Unique Paths":
 *		Now consider if some obstacles are added to the grids. 
 *		How many unique paths would there be? An obstacle and
 *		empty space is marked as 1 and 0 respectively in the grid.
 *		For example,
 *		There is one obstacle in the middle of a 3x3 grid as illustrated below.
		[
		  [0,0,0],
		  [0,1,0],
		  [0,0,0]
		]
 *		The total number of unique paths is 2.
 * TIME:2015-5-12
 * TYPE:DP
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 递归实现
 * 性能：时间复杂度指数级
 */
class Solution_1 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		return uniquePathsWithObstacles(obstacleGrid, 1, 1);
	}
private:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int i, int j) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		if (i == m && j == n)
			return 1;
		else if (i == m && obstacleGrid[i - 1][j] != 1)
			return uniquePathsWithObstacles(obstacleGrid, i, j + 1);
		else if (j == n && obstacleGrid[i][j - 1] != 1)
			return uniquePathsWithObstacles(obstacleGrid, i + 1, j);
		else if (i != m && j != n && obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] != 1)
			return uniquePathsWithObstacles(obstacleGrid, i + 1, j) + uniquePathsWithObstacles(obstacleGrid, i, j + 1);
		else if (j != n && obstacleGrid[i - 1][j] != 1)
			return uniquePathsWithObstacles(obstacleGrid, i, j+1);
		else if (i != m && obstacleGrid[i][j - 1] != 1)
			return uniquePathsWithObstacles(obstacleGrid, i+1, j);
		else
			return 0;
	}
};

/* 迭代法实现
 */
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		else if (obstacleGrid[0].size() == 0)
			return 0;
		else if (m == 1 && obstacleGrid[0].size() == 1)
			if (obstacleGrid[0][0] != 1)//只有1 x 1时其值可能为0、1
				return 1;
			else
				return 0;
		else {
			int n = obstacleGrid[0].size();
			int i = 0, j = 0;
			int **res = new int*[m];
			for (i = 0; i < m; i++)
				res[i] = new int[n];
			i = 0;
			while (i < m && obstacleGrid[i][0] != 1) //第0列中障碍物前面的都为1
				res[i++][0] = 1;
			while (i < m) //障碍物及其后均为0
				res[i++][0] = 0;
			j = 0;
			while (j < n && obstacleGrid[0][j] != 1)//第0行中障碍物前面都为1
				res[0][j++] = 1;
			while (j < n)//障碍物及其后均为0
				res[0][j++] = 0;

			for (int i = 1; i < m; i++){
				for (int j = 1; j < n; j++){
					if (obstacleGrid[i][j] == 1){ //如果为障碍物
						res[i][j] = 0;
						continue;
					}
					res[i][j] = res[i - 1][j] + res[i][j - 1];
				}
			}
			return res[m - 1][n - 1];
		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	int n = 3;
	vector<vector<int>> obstacleGrid;
	for (int j = 0; j < 1; j++)
		v.push_back(0);
	for (int i = 0; i < 2; i++)
		obstacleGrid.push_back(v);
	//obstacleGrid[0][0] = 0;
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	system("pause");
}