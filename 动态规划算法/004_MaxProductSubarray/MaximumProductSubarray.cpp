/* TITLE:Maximum Product Subarray
 *		Find the contiguous subarray within an array (containing at least one number)
 *		which has the largest product.
 *		For example, given the array [2,3,-2,4],
 *		the contiguous subarray [2,3] has the largest product = 6
 *
 * TIME:2015-5-9
 * FROM:leetcode
 * TYPE:DP
 * TEST:VS2013 and Leetcode
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* ����Ŀ����������������������͵�����
 * ���ܣ�ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)
 * ��������㷨��ʲô�ط������׵ģ���ο�helpĿ¼��Maximum Product Subarray  LeetCode OJ.mht
 */
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() <= 0)
			return 0;
		else{
			int curr = nums.at(0);
			int Max, Min;
			int res; //������ֵ
			Max = Min = curr; //Max����ʱ������С
			res = curr;
			for (int i = 1; i < nums.size(); i++){
				curr = nums.at(i);
				int tmp = Max; //����һ��
				Max = max(curr, max(curr * Min, curr * tmp)); //Max�Ѿ�����, ����0ʱ��Max��Min��Ϊ0
				Min = min(curr, min(curr * Min, curr * tmp));
				if (Max > res) //�µ�Max�Ƚ��Ҫ��
					res = Max;
			}
			return res;
		}
	}
};

int main()
{
	vector<int>nums;
	Solution s;
//	int a[] = { 2, 3, -2, 4 }; //6
//	int a[] = {-3, 5, 0, 7, 8};
//	int a[] = {-3, 5, 7, 1};
	int a[] = {101, 0, -1, 100, -3, 5};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		nums.push_back(a[i]);
	cout << s.maxProduct(nums) << endl;
	system("pause");
}