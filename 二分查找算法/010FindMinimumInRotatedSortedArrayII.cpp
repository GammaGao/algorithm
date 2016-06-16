/* TITLE:Find Minimum in Rotated Sorted Array
 *		Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element.
 * NOTE:The array may contain duplicates.(�������ظ�Ԫ��)
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
* ���ܣ�ʱ�临�Ӷ�O(logn)��ע��������ظ�Ԫ��, �������˻���O(n)
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1 || nums[nums.size() - 1] > nums[0])
			return nums[0];
		int p = 0, q = nums.size() - 1;
		while (q - p != 1){
			int mid = (p + q) / 2;
			if (nums[mid] == nums[p] && nums[mid] == nums[q]) //�ظ�Ԫ��
				return findLinear(nums);
			if (nums[mid] >= nums[p]) //ȡ�Ⱥ�ʱnums[mid] == nums[p] != nums[q]
				p = mid; //midȷ����������򲿷�,mid+1���޷�ȷ��
			else// if (nums[mid] < nums[q])
				q = mid; //midȷ�����ұߵ����򲿷�,mid-1�޷�֪��
		}
		return nums[q];
	}

private:
	int findLinear(vector<int> nums)
	{
		int min = nums[0];
		for (int i = 1; i < nums.size() - 1; i++)
			if (nums[i] < min)
				min = nums[i];
		return min;
	}
};

int main()
{
	Solution sl;
	vector<int> nums = { 4, 5, 6, 0, 1, 2 };
	cout << sl.findMin(nums) << endl;

	vector<int> nums1 = { 4, 1 };
	cout << sl.findMin(nums1) << endl;

	vector<int> nums2 = { 4 };
	cout << sl.findMin(nums2) << endl;

	vector<int> nums3 = { 3, 0, 1, 2 };
	cout << sl.findMin(nums3) << endl;

	vector<int> nums4 = { 1, 2, 3, 4 }; //ȫ����
	cout << sl.findMin(nums4) << endl;

	vector<int> nums5 = { 3,3,3,3,1,1,2 };
	cout << sl.findMin(nums5) << endl;

	vector<int> nums6 = { 5, 5, 5, 5, 2, 4, 5 };
	cout << sl.findMin(nums6) << endl;
	system("pause");
}