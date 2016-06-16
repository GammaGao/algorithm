/* TITLE: Maximum Subarray 
 *		Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
 *		For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 *		the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
 * 
 * TIME:2015-5-12
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* DP，时间复杂度O(n)
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int local_sum = nums.at(0);  //局部求和
		int global_max = nums.at(0); //保存最终最大值
		int tmp;
		for (int i = 1; i < nums.size(); i++){
			if (local_sum < 0) //累加和小于0时，可以直接丢弃
				local_sum = 0;
			local_sum += nums.at(i);
			if (local_sum > global_max) //求的和比结果值要大
				global_max = local_sum;
		}
		return global_max;
	}
};


int main()
{
	//vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	//vector<int> nums = {-1, -1, 2, 6, -9, 10};
	vector<int> nums = { -1, -1};
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	system("pause");
}