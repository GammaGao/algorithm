/* TITLE:Maximum Product Subarray
 *		Find the contiguous subarray within an array (containing at least one number)
 *		which has the largest product.
 *		For example, given the array [2,3,-2,4],
 *		the contiguous subarray [2,3] has the largest product = 6
 *
 * TIME:2015-5-9
 * FROM:leetcode
 * TYPE:DP
 * TEST:VS2013 and Leetcode
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 此题目类似于求数组的最大子数组和的问题
 * 性能：时间复杂度O(n), 空间复杂度O(1)
 * 对于这个算法有什么地方不明白的，请参考help目录中Maximum Product Subarray  LeetCode OJ.mht
 */
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() <= 0)
			return 0;
		else{
			int curr = nums.at(0);
			int Max, Min;
			int res; //最后最大值
			Max = Min = curr; //Max是临时最大和最小
			res = curr;
			for (int i = 1; i < nums.size(); i++){
				curr = nums.at(i);
				int tmp = Max; //备份一次
				Max = max(curr, max(curr * Min, curr * tmp)); //Max已经更新, 出现0时，Max和Min均为0
				Min = min(curr, min(curr * Min, curr * tmp));
				if (Max > res) //新的Max比结果要大
					res = Max;
			}
			return res;
		}
	}
};

int main()
{
	vector<int>nums;
	Solution s;
//	int a[] = { 2, 3, -2, 4 }; //6
//	int a[] = {-3, 5, 0, 7, 8};
//	int a[] = {-3, 5, 7, 1};
	int a[] = {101, 0, -1, 100, -3, 5};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		nums.push_back(a[i]);
	cout << s.maxProduct(nums) << endl;
	system("pause");
}