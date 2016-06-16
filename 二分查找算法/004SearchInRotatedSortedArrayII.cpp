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

/* �����������ظ�Ԫ��ʱ��������ͨ���ֲ��㷨��֮ͬ�����ڣ����ֵ�������ӵĿ��ǵ����
 * �磺 1, 3, 1, 1, 1�� ��ʱpos = (0+4)/2=2, nums[0] == nums[pos]�����ֽ�ʧЧ�� 1�� 3�� 1������벿�����
 * ��������£�ֻ����˳�����O(n)
 * ���ܣ�O(logn)
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
			if (nums.at(pos) >= nums.at(p)){ //��벿����
				if (nums.at(pos) == nums.at(p) && pos != p)
					return findOrder(nums, target);
				if (target >= nums.at(p) && target < nums.at(pos)) //ȷ��target����벿
					q = pos - 1;
				else
					//��ʱ������������£� target����벿��target������벿
					p = pos + 1;
			}
			else { //�Ұ벿����
				if (target <= nums.at(q) && target > nums.at(pos)) //ȷ��target���Ұ벿
					p = pos + 1;
				else
					//target���Ұ벿��target�����Ұ벿
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