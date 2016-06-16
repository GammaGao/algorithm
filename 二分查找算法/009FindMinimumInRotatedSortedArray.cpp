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

/* ˼·�����ֲ�����ת���飬������������p��q���ֱ�ָ��ǰ��ͺ�벿��
 * ���ܣ�ʱ�临�Ӷ�O(logn)��ע��û���ظ�Ԫ��
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
				p = mid; //midȷ����������򲿷�,mid+1���޷�ȷ��
			else// if (nums[mid] < nums[q])
				q = mid; //midȷ�����ұߵ����򲿷�,mid-1�޷�֪��
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

	vector<int> nums4 = {1,2,3,4}; //ȫ����
	cout << sl.findMin(nums4) << endl;
	system("pause");
}