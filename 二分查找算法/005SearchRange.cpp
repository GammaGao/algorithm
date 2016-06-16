/* TITLE: Search for a Range 
 *		Given a sorted array of integers, find the starting and ending position of a given target value.
 *		Your algorithm's runtime complexity must be in the order of O(log n).
 *		If the target is not found in the array, return [-1, -1].
 *		For example,
 *		Given [5, 7, 7, 8, 8, 10] and target value 8,
 *		return [3, 4].
 *
 * TIME:2015-5-15
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* ˼·�����ֲ���
 * ���ܣ�����ʱ�临�Ӷ�O(logn)
 */
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = {-1, -1};
		if (nums.size() == 0)
			return res;
		int p = 0, q = nums.size() - 1;
		while (p <= q){
			int mid = (p + q) / 2;
			if (nums.at(mid) == target){
				res[0] = res[1] = mid; //�ҵ���һ��Ŀ��
				int left = searchRange_left(nums, 0, mid-1, target); //��ݹ�����ҵ�����ߵ�λ��
				int right = searchRange_right(nums, mid+1, nums.size() - 1, target); //�ҵݹ��ҵ����ұߵ�λ��
				if (left != -1)
					res[0] = left;
				if (right != -1)
					res[1] = right;
				return res;
			}
			else if (nums.at(mid) > target)
				q = mid - 1;
			else
				p = mid + 1;
		}
		return res;
	}
private:
	int searchRange_left(vector<int> &nums, int start, int end, int target)
	{
		if (nums.size() == 0)
			return -1;
		int p = start, q = end;
		while (p <= q){
			int mid = (p + q) / 2;
			if (nums.at(mid) == target){
				int tmp = searchRange_left(nums, start, mid - 1, target); //����
				return tmp == -1 ? mid : tmp;
			}
			else if (nums.at(mid) > target)
				q = mid - 1;
			else
				p = mid + 1;
		}
		return -1;
	}

	int searchRange_right(vector<int> &nums, int start, int end, int target)
	{
		if (nums.size() == 0)
			return -1;
		int p = start, q = end;
		while (p <= q){
			int mid = (p + q) / 2;
			if (nums.at(mid) == target){
				int tmp = searchRange_right(nums, mid+1, end, target); //����
				return tmp == -1 ? mid : tmp;
			}
			else if (nums.at(mid) > target)
				q = mid - 1;
			else
				p = mid + 1;
		}
		return -1;
	}
};

int main()
{
	Solution sl;
	vector<int> res;
	//vector<int> nums = { 5, 7, 7, 7, 8, 8, 10 };
	vector<int> nums = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	res = sl.searchRange(nums, 3);
	cout << "[" << res[0] << " " << res[1] << "]" << endl;
	system("pause");
}