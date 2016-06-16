/* TITLE: Find Peak Element(数学中的极大值点)
 *		A peak element is an element that is greater than its neighbors.
 *		Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *		The array may contain multiple peaks, in that case return the index to any one of the
 *		peaks is fine. You may imagine that num[-1] = num[n] = -∞.
 *		For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * TIME:2015-5-17
 * FROM:leetcode
 * TYPE:binary search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 二分查找算法找极大值
 */
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return 0;
		int p = 0, q = nums.size() - 1;
		p++; q--;
		while (p <= q){
			int mid = (p + q) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) //满足要求的极大点
				return mid;
			else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) //一定有一个极大值点出现在右边
				p = mid + 1;
			else //一定有一个极大值点出现在左边
				q = mid - 1;
		}
		//如果上述无果，它是递增序列或递减序列，极大值出现在首和尾
		return nums[1] < nums[0] ? 0 : nums.size() - 1;
	}
};

int main()
{
	//vector<int> nums = {2, 3, 1, 2, 4, 3}; //return index 1 or 4
	//vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 }; //return 7
	//vector<int> nums = {8,7,6,5,5,4,3,2,1};
	//vector<int> nums = { 1, 2 };
	vector<int> nums = {10,1};
	Solution sl;
	cout << sl.findPeakElement(nums) << endl;
	system("pause");
}