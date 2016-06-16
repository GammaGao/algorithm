/* @TITLE: Permutations��ȫ���У�
 *		Given a collection of numbers, return all possible permutations.
 *		For example,
 *		[1,2,3] have the following permutations:
 *		[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].	
 *
 * @TIME:2015-5-23
 * @FROM:leetcode
 * @TYPE:backtracking
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* ���ݲ���ָǰ�������
 * �磬1,2,3,����2,3�������Ѿ��źã���ôֻ��Ҫ��1,���ٺ��ʵ�λ�ñ����(ͨ��������ɣ����ǲ���)
 */
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permute(res, nums, 0);
		return res;
	}
private:
	void permute(vector<vector<int>> &res, vector<int> &nums, int start)
	{
		if (start == nums.size() - 1)
			res.push_back(nums);
		for (int i = start; i < nums.size(); i++){
			swap(nums[start], nums[i]); //����
			permute(res, nums, start+1);
			swap(nums[start], nums[i]); //���أ��Ա������һ�δ�����ʹ��л���˼��
		}
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = { 1, 2, 3 };
	//vector<int> nums = { 1 };
	//vector<int> nums = { 1, 2 };
	vector<int> nums = { 1, 1 };
	vector<vector<int>> res;
	res = sl.permute(nums);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}