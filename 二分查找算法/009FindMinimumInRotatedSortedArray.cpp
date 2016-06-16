/* TITLE:Find Minimum in Rotated Sorted Array
 *		Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element.
 *		You may assume no duplicate exists in the array.
 *
 * TIME:2015-5-17
 * TYPE:binary search
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 思路：二分查找旋转数组，定义两个索引p和q，分别指向前半和后半部分
 * 性能：时间复杂度O(logn)，注意没有重复元素
 */
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1 || nums[nums.size() - 1] > nums[0])
			return nums[0];
		int p = 0, q = nums.size() - 1;
		while (q - p != 1){
			int mid = (p + q) / 2;
			if (nums[mid] > nums[p])
				p = mid; //mid确定在左边有序部分,mid+1就无法确定
			else// if (nums[mid] < nums[q])
				q = mid; //mid确定在右边的有序部分,mid-1无法知道
		}
		return nums[q];
	}
};

int main()
{
	Solution sl;
	vector<int> nums = {4,5,6,0,1,2};
	cout << sl.findMin(nums) << endl;

	vector<int> nums1 = { 4, 1};
	cout << sl.findMin(nums1) << endl;

	vector<int> nums2 = { 4};
	cout << sl.findMin(nums2) << endl;

	vector<int> nums3 = { 3,0,1,2 };
	cout << sl.findMin(nums3) << endl;

	vector<int> nums4 = {1,2,3,4}; //全递增
	cout << sl.findMin(nums4) << endl;
	system("pause");
}