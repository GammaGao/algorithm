/* TITLE: Search in Rotated Sorted Array II
*		Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*		You are given a target value to search. If found in the array return its index, otherwise return -1.

*		Follow up for "Search in Rotated Sorted Array":
*		What if duplicates are allowed?
*		Would this affect the run-time complexity? How and why?
*		Write a function to determine if a given target is in the array.
* NOTE: there may be some duplicate elements in the array.
* TIME:2015-5-15
* FROM:leetcode
* TYPE:binary search
* AUTHOR:PengSc
*/
#include <iostream>
#include <vector>
using namespace std;

/* 当数组中有重复元素时，它与普通二分查算法不同之处在于，二分的情况增加的考虑的情况
 * 如： 1, 3, 1, 1, 1， 此时pos = (0+4)/2=2, nums[0] == nums[pos]，二分将失效， 1， 3， 1并非左半部有序的
 * 这种情况下，只能用顺序查找O(n)
 * 性能：O(logn)
 */
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int pos = -1;
		if (nums.size() == 0)
			return -1;
		int p = 0, q = nums.size() - 1;
		while (p <= q){
			pos = (p + q) / 2;
			if (nums.at(pos) == target)
				return true;
			if (nums.at(pos) >= nums.at(p)){ //左半部有序
				if (nums.at(pos) == nums.at(p) && pos != p)
					return findOrder(nums, target);
				if (target >= nums.at(p) && target < nums.at(pos)) //确定target在左半部
					q = pos - 1;
				else
					//此时有两种情况导致， target在左半部，target不在左半部
					p = pos + 1;
			}
			else { //右半部有序
				if (target <= nums.at(q) && target > nums.at(pos)) //确定target在右半部
					p = pos + 1;
				else
					//target在右半部或target不在右半部
					q = pos - 1;
			}
		}
		return false;
	}
private:
	bool findOrder(vector<int> nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
			if (nums.at(i) == target)
				return true;
		return false;
	}
};

int main()
{
	Solution sl;
	vector<int> nums1 = {4, 4, 0, 1, 4, 4};
	cout << sl.search(nums1, 4) << endl;

	vector<int> nums2 = { 1, 3, 1, 1, 1 };
	cout << sl.search(nums2, 0) << endl;
	//vector<int> nums = { 3, 1 };
	
	system("pause");
}