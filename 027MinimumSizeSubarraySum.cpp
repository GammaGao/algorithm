/* TITLE: Minimum Size Subarray Sum(子数组是连续的，而子序列是不连续的)
 *		Given an array of n positive integers and a positive integer s,
 *		find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *		For example, given the array [2,3,1,2,4,3] and s = 7,
 *		the subarray [4,3] has the minimal length under the problem constraint.
 *
 *		More practice: If you have figured out the O(n) solution, try coding another solution of which the
 *					time complexity is O(n log n).
 *
 * TIME:2015-5-17
 * FROM:leetcode
 * TYPE:DP/Binary Search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 动态规划算法：扫描整个数组如:2,3,1,2,4,3,7， s=7， 当index=2时，前面的四个数相加为8>=7
 *			于是min被更新为4，继续往后，扫描到index=5时，前面的两个数4+3长度为2< min=4,故
 *			min被更新为2,继续，扫描到7时，长度为1<min=2，故min被更新为1。
 * 性能：时间复杂度O(n^2)
 * 缺点：从后往前找时，在最坏情况找的次数是1+2+3..+n
 * 改进：从前往后找
 */
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums[0] >= s)
			return 1;

		int sum = 0;
		int j = 0;
		int min = 0; //保存满足要求的最小长度
		for (int i = 0; i < nums.size(); i++){
			sum = 0;
			j = i;
			while (j >= 0){ //从当前数往 前 找
				sum += nums[j];
				if (sum >= s){
					if (min == 0 || i - j + 1 < min){
						min = i - j + 1;
						break;
					}
				}
				j--;
			}
		}
		return min;
	}
};

/* 思路：类似滑动窗口思路，sliding window
 * 性能：时间复杂度O(n)
 */
class Solution_1 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int num_len = nums.size();
		int left = 0, right = 0, total = 0, min_len = num_len + 1;
		while (right < num_len) {
			// move right silder forward till total >= s
			do { total += nums[right++]; } while (right<num_len && total< s);
			// move left slider forward while maintaining total >= s
			while (left<right && total - nums[left] >= s) total -= nums[left++];
			// record if it's the minimum
			if (total >= s && min_len> right - left)
				min_len = right - left;
		}
		return min_len <= num_len ? min_len : 0;
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = {2,3,1,2,4,3,7}; //1
	//vector<int> nums = { 2, 3, 1, 2, 4, 3}; //2
	//vector<int> nums = { 7, 1};
	vector<int> nums = { 1, 1 };

	cout << sl.minSubArrayLen(3, nums);
	system("pause");
}