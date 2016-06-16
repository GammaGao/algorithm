/* TITLE: Search Insert Position 
 *		Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *		You may assume no duplicates in the array. Here are few examples.
		[1,3,5,6], 5 → 2
		[1,3,5,6], 2 → 1
		[1,3,5,6], 7 → 4
		[1,3,5,6], 0 → 0 
 *
 * TIME: 2015-5-14
 * TYPE: binary search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 二分查找实现
 */
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int p = 0, q = nums.size()-1;
		int insertPos;
		while (p <= q){
			insertPos = (p + q) / 2;
			if (nums.at(insertPos) == target)
				return insertPos;
			else if (nums.at(insertPos) > target)
				q = insertPos - 1;
			else
				p = insertPos + 1;
		}
		return p;
	}
};

int main()
{
	Solution sl;
	vector<int> nums;// = { 1, 3, 5, 6 };
	cout << sl.searchInsert(nums, 2) << endl;
	system("pause");
}