/* TITLE: Unique Paths
 *		A robot is located at the top-left corner of a m x n grid (marked 'Start' 
 *		in the diagram below). The robot can only move either down or right at any
 *		point in time. The robot is trying to reach the bottom-right corner of the
 *		grid (marked 'Finish' in the diagram below). How many possible unique paths
 *		are there?
 *
 * TIME:2015-5-11
 * FROM:leetcode
 * TYPE:DP
 * AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

/* 简洁的递归实现，有很多子问题是重叠的
 * 性能：时间复杂度指数级别
 */
class Solution_1 {
public:
	int uniquePaths(int m, int n) {
		return uniquePaths(1, 1, m, n);
	}
private:
	int uniquePaths(int i, int j, int m, int n) {
		int count = 0;
		if (i == m && j == n)
			return 1;
		else if (i == m)
			return uniquePaths(i, j + 1, m, n);
		else if (j == n)
			return uniquePaths(i+1, j, m, n);
		else{
			return uniquePaths(i+1, j, m, n) + uniquePaths(i, j+1, m, n);
		}
	}
};

/* 迭代法实现
 * 思路：f(m,n)=f(m-1, n)+f(m,n-1)
 * 性能：时间复杂度O(m*n)，空间复杂度O(m*n)
 */
class Solution {
public:
	int uniquePaths(int m, int n) {
		int **res = new int*[m];
		for (int i = 0; i < m; i++)
			res[i] = new int[n];
		for (int i = 0; i < m; i++)
			res[i][0] = 1;
		for (int j = 0; j < n; j++)
			res[0][j] = 1;
		if (m == 1 || n == 1)
			return 1;
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				res[i][j] = res[i-1][j] + res[i][j-1];
			}
		}
		return res[m - 1][n - 1];
	}
};

int main()
{
	Solution s;
	cout << s.uniquePaths(1, 1) << endl; //1
	cout << s.uniquePaths(1,2) << endl; //1
	cout << s.uniquePaths(5, 1) << endl; //1
	cout << s.uniquePaths(2, 2) << endl; //2
	cout << s.uniquePaths(3, 2) << endl; //3
	cout << s.uniquePaths(2, 3) << endl; //3
	cout << s.uniquePaths(23, 12) << endl; //193536720, 递归运行时间1分钟左右， 循环运行不到2ms
	system("pause");
}