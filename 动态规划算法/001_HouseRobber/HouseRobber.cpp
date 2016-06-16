/* TITLE: House Robber
 *		You are a professional robber planning to rob houses along a street. Each house
 *		has a certain amount of money stashed, the only constraint stopping you from robbing
 *		each of them is that adjacent houses have security system connected and it will automatically
 *		contact the police if two adjacent houses were broken into on the same night.
 *		Given a list of non-negative integers representing the amount of money of each house,
 *		determine the maximum amount of money you can rob tonight without alerting the police.
 * TIME��2015-5-8
 * FROM��leetcode
 * TYPE: Dynamically Programming
 */
#include <iostream>
#include <vector>
using namespace std;

/* �������⣬����Ķ�̬�滮�㷨�� ����������ԭʼ�ĵݹ��㷨��⣬δ���Ż�
 * ʱ�临�Ӷȣ�ָ������
 */
class Solution_1 {
public:
	int rob(vector<int>& nums) {
		return rob(nums, nums.size()-1);
	}
private:
	int rob(vector<int> &nums, int n)
	{
		int robbed = 0, unrobbed = 0;
		if (n < 0)
			return 0;
		else if (n == 0)
			return nums.at(0);
		else if (n < 2)
			return max(nums.at(0), nums.at(1));

		if (n >= 2)
			robbed = nums.at(n) + rob(nums, n - 2);
		unrobbed = rob(nums, n-1);
		return max(robbed, unrobbed);
	}

	int max(int a, int b)
	{
		return a >= b ? a : b;
	}
};

/* ��̬�滮�㷨ͨ��ʹ�õ��Ǵ�Ŀ¼�ĵݹ�ʵ�ֺ�ѭ��ʵ��
 * ʱ�临�Ӷ�ΪO(n)
 */
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n == 1)
			return nums.at(0);
		else{ //robbed��ʾ��ǰ�㱻����unrobbed��ǰ��û����
			int robbed = nums.at(1), unrobbed = nums.at(0), tmp;
			for (int j = 2; j < n; j++){
				tmp = robbed; //����
				/* ��ǰ�������������Ƹ�ֵ��max{��ǰ��ĲƸ�+��һ��û���������ֵ, ��һ�㱻�������ֵ} */
				robbed = max(nums.at(j)+unrobbed, robbed); //����robbed��ֵ
				/* ��ǰ����û���������Ƹ�ֵ��max{��һ��û���������ֵ, ��һ�㱻�������ֵ} */
				unrobbed = max(tmp, unrobbed);
			}
			return max(robbed, unrobbed);
		}
	}
private:
	int max(int a, int b)
	{
		return a >= b ? a : b;
	}
};

int main()
{
//	int a[] = {1}; //1
//	int a[] = {1, 100}; //100
//	int a[] = {5, 10, 100}; //5+100
//	int a[] = {5, 1, 2, 10}; //5+10
//	int a[] = {1,2,3,4,5,6,7,8}; //2+4+6+8=20
//	int a[] = {1, 10, 10, 11}; //10+11
	int a[] = { 104, 209, 137, 52, 158, 67, 213, 86, 141,\
		110, 151, 127, 238, 147, 169, 138, 240, 185, 246, 225,\
		147, 203, 83, 83, 131, 227, 54, 78, 165, 180, 214, 151,\
		111, 161, 233, 147, 124, 143 }; //3176, �õݹ��㷨����Ļ�����Ҫ�ü���

	Solution s;
	vector<int> in;
	for (int i = 0; i < sizeof(a) / sizeof(int); i++){
		in.push_back(a[i]);
	}
	cout << s.rob(in) << endl;
	system("pause");
}