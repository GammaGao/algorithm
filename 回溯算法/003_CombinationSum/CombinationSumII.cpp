/* TITLE: Combination Sum II
 *		Given a collection of candidate numbers (C) and a target number (T),
 *		find all unique combinations in C where the candidate numbers sums to T.
 *		Each number in C may only be used once(每个元素只限使用一次) in the combination.
 *		Note:
 *		All numbers (including target) will be positive integers.
 *		Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *		The solution set must not contain duplicate combinations.
 *		For example, given candidate set 10,1,2,7,6,1,5 and target 8,(初始集合中可以有重复元素)
 *		A solution set is:
		 [1, 7]
		 [1, 2, 5]
		 [2, 6]
		 [1, 1, 6]
 *
 * TYPE:backtracking
 * TIME:2015-5-20
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 回溯算法：和Combination SumI 相比，查找是一一颗有限的树而非无限的树
 *		如：[1,1,2,5,6,7,10]
						 [					空根							   ]
					  /       \    \            \			   \        \    \
				    [1]		  [1]   [2]             [5]        [6]      [7]  [10]
			 /  /  /  \  \  \     /  \  \   \     \  \  \       / \      |
			[1][2][5][6][7][10]  [5] [6] [7] [10] [6] [7] [10] [7] [10] [10]
 * 图中未画出第二个1的子树，因为若存在解，它的解包含在第一个1的子树中，为防止重复，不进行访问
 */
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;//最终结果
		vector<int> vec;
		int sum = 0;
		sort(candidates.begin(), candidates.end()); //先排好序
		combinationSum2(res, vec, candidates, target, sum, 0);
		return res;
	}

private:
	void combinationSum2(vector<vector<int>>&res, vector<int> &vec,
		vector<int> &candidates, int target, int &sum, int start)
	{
		int tmp = 0; //保存上一次回溯的状态
		for (int i = start; i < candidates.size(); i++){
			if (tmp == candidates[i]) //如果上一次回溯状态跟下一次相同，跳过重复的
				continue;
			sum += candidates[i];
			if (sum == target){ //找到满足要求的组和最后一个数
				vec.push_back(candidates[i]);
				res.push_back(vec); //记录

				sum -= vec.back(); //回溯到上一状态，搜索其它满足要求的值
				tmp = vec.back();
				vec.pop_back();
				return;
			}
			else if (sum < target){
				vec.push_back(candidates[i]);
				combinationSum2(res, vec, candidates, target, sum, i+1); //注意combination sumI中，最后一个参数是i,这儿是i+1
				sum -= vec.back(); //回溯到上一状态，搜索其它值
				tmp = vec.back();
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
	//vector<int> candidates = { 3 };
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> res;
	Solution sl;
	res = sl.combinationSum2(candidates, 8);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}