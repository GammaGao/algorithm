/* @TITLE: Permutations II
 *		Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *		For example,
 *		[1,1,2] have the following unique permutations:
 *		[1,1,2], [1,2,1], and [2,1,1].
 *
 * @TIME:2015-5-26
 * @TYPE:backtracking
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		permuteUnique(res, nums, 0);
		return res;
	}
private:
	void permuteUnique(vector<vector<int>> &res, vector<int> &nums, int start)
	{
		if (start == nums.size()){
			res.push_back(nums);
			return;
		}
		unordered_set<int> swapped; //使用unordered_set容器消除重复
		for (int i = start; i < nums.size(); i++){
			if (swapped.count(nums[i]) == 1){ //找到重复元素
				continue;
			}
			swapped.insert(nums[i]);
			swap(nums[start], nums[i]);
			permuteUnique(res, nums, start + 1);
			swap(nums[start], nums[i]);
		}
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = {1};
	//vector<int> nums = { 1,1,2};
	vector<int> nums = { 2, 1, 1 };
	//vector<int> nums = { 1,1,2,2};
	vector<vector<int>> res;
	res = sl.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}