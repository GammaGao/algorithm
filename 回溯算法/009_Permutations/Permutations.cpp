/* @TITLE: Permutations（全排列）
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

/* 回溯不单指前进与后退
 * 如，1,2,3,假设2,3的排列已经排好，那么只需要把1,放再合适的位置便可以(通过交换完成，不是插入)
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
			swap(nums[start], nums[i]); //交换
			permute(res, nums, start+1);
			swap(nums[start], nums[i]); //换回，以便进行下一次处理，这就带有回溯思想
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