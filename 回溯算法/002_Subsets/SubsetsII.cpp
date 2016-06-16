/* TITLE: SubsetsII
*		Given a set of distinct integers, nums, return all possible subsets.
*		Note:
*			Elements in a subset must be in non-descending order.
*			The solution set must not contain duplicate subsets.
*			There may be dupicate elements in the set.
*		For example,
*		If nums = [1,2,2], a solution is:
		[
		[1],
		[2],
		[1,2,2],
		[1,2],
		[2,2],
		[]
		]
*
* TIME:2015-5-21
* TYPE:backtrace(回溯算法)
* AUTHOR:PengSc
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 普通做法：{1,2，3}先把第一次扫描每一个数，先把空集放入容器，再把1放入容器；
*		第二次扫描，再把容器前面的数读出来加上2，再添加到容器尾部。
* 性能：时间复杂度O(2^n),因为子集个数为2^n个。
*/
class Solution_1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		vector<int> v;
		ret.push_back(v);
		for (int i = 0; i < nums.size(); i++){
			int n = ret.size();
			for (int j = 0; j < n; j++){
				v = ret[j]; //取出之前的
				v.push_back(nums[i]); //在每个数后添加新数
				ret.push_back(v); //再添加到结果中去
			}
		}
		return ret;
	}
};

/* 回溯算法：回溯并不是指递归，它是一种设计思路，一种系统系统的搜索结果的方法。
*		先访问空集[], 再访问1，再回溯至[],再访问2,再回溯,再访问3；其中的每一步可以看做一个子过程。
*		如访问到1时，可回溯也可再深度访问。画成树如下（变成了Tire树）：
		[ ] //空集
		/      |    \
		[1]     [2]    [3]
		/  \      /
		[1,2] [1,3] [2,3]
		/
		[1,2,3]
* 回溯算法的典型应用：幂集问题（本题）、图（迷宫问题）、树（访问树本质上就是回溯）
*/
class Solution {
public:
	std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int> > res;
		std::vector<int> vec;
		int tmp;
		subsets(res, nums, vec, 0, tmp);
		return res;
	}
private:
	void subsets(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin, int &tmp) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i) {
			if (nums[i] == tmp)
				continue;
			vec.push_back(nums[i]);
			subsets(res, nums, vec, i + 1, tmp);
			tmp = vec.back();
			vec.pop_back(); //回溯至上状态
		}
	}
};

int main()
{
	Solution sl;
	//vector<int> nums = { 1, 2, 4, 5, 8, 7 };
	vector<int> nums = { 1, 2, 2 };
	vector<vector<int>> res;
	res = sl.subsetsWithDup(nums);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}