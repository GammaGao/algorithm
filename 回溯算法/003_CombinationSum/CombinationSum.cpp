/* TITLE: Combination Sum(组合求和)
 *		Given a set of candidate numbers (C) and a target number (T),
 *		find all unique combinations in C where the candidate numbers sums to T.
 *		The same repeated number may be chosen from C unlimited number of times.
 *
 *		Note:
 *		All numbers (including target) will be positive integers.
 *		Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *		The solution set must not contain duplicate combinations.
 *		For example, given candidate set 2,3,6,7 and target 7, 
 *		A solution set is: 
			[7] 
			[2, 2, 3]
 * TYPE:backtracking(回溯)
 * TIME:2015-5-19
 * AUTHOR:PengSc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 回溯算法:排列组和，解决这类问题利器
 * 如：[2,3,6,7]因为其中的每个数可以无限次重复，实际上回溯变成了访问一颗无穷树
 *						    []
					  /         \           \      \
					[2]			[3]		   [6]		[7]
				/  /   \  \     /  \  \     /  \     \
 			  [2] [3] [6] [7]  [3] [6] [7] [6] [7]   [7]
			...   ... ... ...  ... ... ... ... ...   ...
			  （即2下有2，3,6,7； 3下有3,6,7把2去掉是因为组和不允许重复)
 * 回溯算法想象成访问的是树或图。
 */
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;//最终结果
		vector<int> vec;
		int sum = 0;
		sort(candidates.begin(), candidates.end()); //先排好序
		combinationSum(res, vec, candidates, target, sum, 0);
		return res;
	}

private:
	void combinationSum(vector<vector<int>>&res, vector<int> &vec, 
		vector<int> &candidates, int target, int &sum, int start)
	{
		for (int i = start; i < candidates.size(); i++){
			sum += candidates[i];
			if (sum == target){ //找到满足要求的组和最后一个数
				vec.push_back(candidates[i]);
				res.push_back(vec); //记录

				sum -= vec.back(); //回溯到上一状态，搜索其它满足要求的值
				vec.pop_back();
				return;
			}
			else if (sum < target){
				vec.push_back(candidates[i]);
				combinationSum(res, vec, candidates, target, sum, i);
				sum -= vec.back(); //回溯到上一状态，搜索其它值
				vec.pop_back();
			}
			else{
				sum -= candidates[i];
				return;
			}
		}
	}
};

int main()
{
	//vector<int> candidates = { 2, 3, 6, 7 };
	//vector<int> candidates = { 2, 3, 6, 7, 10};
	vector<int> candidates = { 3};
	vector<vector<int>> res;
	Solution sl;
	res = sl.combinationSum(candidates, 10);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}