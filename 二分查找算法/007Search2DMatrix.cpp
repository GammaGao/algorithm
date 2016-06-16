/* TITLE: Search a 2D Matrix 
 *		Write an efficient algorithm that searches for a value in an m x n matrix.
 *		This matrix has the following properties:
 *		Integers in each row are sorted from left to right.
 *		The first integer of each row is greater than the last integer of the previous row.
 *		For example, Consider the following matrix:
		[
		  [1,   3,  5,  7],
		  [10, 11, 16, 20],
		  [23, 30, 34, 50]
		]
		Given target = 3, return true.
 *
 * TIME:2015-5-16
 * FROM:leetcode
 * TYPE:binary Search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 思路：实际上是在第一列进行二分查找以确定搜索的行，再对该行进行二分查找
 */
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int row = searchRow(matrix, target);
		int p = 0;
		int q = matrix[0].size() - 1;
		while (p <= q){
			int mid = (p + q) / 2;
			if (matrix[row][mid] == target)
				return true;
			else if (matrix[row][mid] > target)
				q = mid - 1;
			else
				p = mid + 1;
		}
		return false;
	}
private:
	/* 对第一列进行二分查找，实际上找到target可能所在的行 */
	int searchRow(vector<vector<int>> &matrix, int target)
	{
		int p = 0, q = matrix.size() - 1;
		if (matrix.size() == 1 || target >= matrix[0][0] && target < matrix[1][0])
			return 0;
		if (target >= matrix[q][0])
			return q;
		p++; q--;
		while (p <= q){
			int mid = (p + q) / 2;
			if (matrix[mid][0] == target)
				return mid;
			else if (matrix[mid][0] > target && target > matrix[mid - 1][0]) //确定target可能在mid-1行
				return mid - 1;
			else if (matrix[mid][0] < target && target < matrix[mid + 1][0]) //确定target可能在mid行
				return mid;
			else if (matrix[mid][0] > target)
				q = mid - 1;
			else
				p = mid + 1;
		}
		return 0; //always non-execute
	}
};

int main()
{
	//vector<vector<int>> nums = { { 1, 3, 5, 7 }, \
								 { 10, 11, 16, 20 },\
								 { 23, 30, 34, 50} };
	vector<vector<int>> nums = { {1} };
	vector<int> v;
	int row;
	int input;
	//cin >> row;
	/*while (row--){
		cin >> input;
		v.push_back(input);
		nums.push_back(v);
		v.clear();
	} */
	Solution sl;
	cout << sl.searchMatrix(nums, 1) << endl;
	system("pause");
}