/* TITLE: Minimum Size Subarray Sum(�������������ģ����������ǲ�������)
 *		Given an array of n positive integers and a positive integer s,
 *		find the minimal length of a subarray of which the sum �� s. If there isn't one, return 0 instead.
 *		For example, given the array [2,3,1,2,4,3] and s = 7,
 *		the subarray [4,3] has the minimal length under the problem constraint.
 *
 *		More practice: If you have figured out the O(n) solution, try coding another solution of which the
 *					time complexity is O(n log n).
 *
 * TIME:2015-5-17
 * FROM:leetcode
 * TYPE:DP/Binary Search
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* ��̬�滮�㷨��ɨ������������:2,3,1,2,4,3,7�� s=7�� ��index=2ʱ��ǰ����ĸ������Ϊ8>=7
 *			����min������Ϊ4����������ɨ�赽index=5ʱ��ǰ���������4+3����Ϊ2< min=4,��
 *			min������Ϊ2,������ɨ�赽7ʱ������Ϊ1<min=2����min������Ϊ1��
 * ���ܣ�ʱ�临�Ӷ�O(n^2)
 * ȱ�㣺�Ӻ���ǰ��ʱ���������ҵĴ�����1+2+3..+n
 * �Ľ�����ǰ������
 */
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums[0] >= s)
			return 1;

		int sum = 0;
		int j = 0;
		int min = 0; //��������Ҫ�����С����
		for (int i = 0; i < nums.size(); i++){
			sum = 0;
			j = i;
			while (j >= 0){ //�ӵ�ǰ���� ǰ ��
				sum += nums[j];
				if (sum >= s){
					if (min == 0 || i - j + 1 < min){
						min = i - j + 1;
						break;
					}
				}
				j--;
			}
		}
		return min;
	}
};

/* ˼·�����ƻ�������˼·��sliding window
 * ���ܣ�ʱ�临�Ӷ�O(n)
 */
class Solution_1 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int num_len = nums.size();
		int left = 0, right = 0, total = 0, min_len = num_len + 1;
		while (right < num_len) {
			// move right silder forward till total >= s
			do { total += nums[right++]; } while (right<num_len && total< s);
			// move left slider forward while maintaining total >= s
			while (left<right && total - nums[left] >= s) total -= nums[left++];
			// record if it's the minimum
			if (total >= s && min_len> right - left)
				min_len = right - left;
		}
		return min_len <= num_len ? min_len : 0;
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = {2,3,1,2,4,3,7}; //1
	//vector<int> nums = { 2, 3, 1, 2, 4, 3}; //2
	//vector<int> nums = { 7, 1};
	vector<int> nums = { 1, 1 };

	cout << sl.minSubArrayLen(3, nums);
	system("pause");
}