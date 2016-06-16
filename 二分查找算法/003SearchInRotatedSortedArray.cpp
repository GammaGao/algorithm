/* TITLE: Search in Rotated Sorted Array
 *		Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *		You are given a target value to search. If found in the array return its index, otherwise return -1.
 *		You may assume no duplicate exists in the array.
 *
 * TIME:2015-5-15
 * FROM:leetcode
 * TYPE:binary search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 它与普通二分查算法不同之处在于，二分的情况增加的考虑的情况
 * 性能：O(logn)
 */
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int pos = -1;
		if (nums.size() == 0)
			return -1;
		int p = 0, q = nums.size()-1;
		while (p <= q){
			pos = (p + q) / 2;
			if (nums.at(pos) == target)
				return pos;
			if (nums.at(pos) >= nums.at(p)){ //左半部有序
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
		return -1;
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = {4, 5, 0, 1, 2, 3};

	vector<int> nums = {3, 1};
	cout << sl.search(nums, 1) << endl;
	system("pause");
}