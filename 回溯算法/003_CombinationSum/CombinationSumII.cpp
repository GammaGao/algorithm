/* TITLE: Combination Sum II
 *		Given a collection of candidate numbers (C) and a target number (T),
 *		find all unique combinations in C where the candidate numbers sums to T.
 *		Each number in C may only be used once(ÿ��Ԫ��ֻ��ʹ��һ��) in the combination.
 *		Note:
 *		All numbers (including target) will be positive integers.
 *		Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
 *		The solution set must not contain duplicate combinations.
 *		For example, given candidate set 10,1,2,7,6,1,5 and target 8,(��ʼ�����п������ظ�Ԫ��)
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

/* �����㷨����Combination SumI ��ȣ�������һһ�����޵����������޵���
 *		�磺[1,1,2,5,6,7,10]
						 [					�ո�							   ]
					  /       \    \            \			   \        \    \
				    [1]		  [1]   [2]             [5]        [6]      [7]  [10]
			 /  /  /  \  \  \     /  \  \   \     \  \  \       / \      |
			[1][2][5][6][7][10]  [5] [6] [7] [10] [6] [7] [10] [7] [10] [10]
 * ͼ��δ�����ڶ���1����������Ϊ�����ڽ⣬���Ľ�����ڵ�һ��1�������У�Ϊ��ֹ�ظ��������з���
 */
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;//���ս��
		vector<int> vec;
		int sum = 0;
		sort(candidates.begin(), candidates.end()); //���ź���
		combinationSum2(res, vec, candidates, target, sum, 0);
		return res;
	}

private:
	void combinationSum2(vector<vector<int>>&res, vector<int> &vec,
		vector<int> &candidates, int target, int &sum, int start)
	{
		int tmp = 0; //������һ�λ��ݵ�״̬
		for (int i = start; i < candidates.size(); i++){
			if (tmp == candidates[i]) //�����һ�λ���״̬����һ����ͬ�������ظ���
				continue;
			sum += candidates[i];
			if (sum == target){ //�ҵ�����Ҫ���������һ����
				vec.push_back(candidates[i]);
				res.push_back(vec); //��¼

				sum -= vec.back(); //���ݵ���һ״̬��������������Ҫ���ֵ
				tmp = vec.back();
				vec.pop_back();
				return;
			}
			else if (sum < target){
				vec.push_back(candidates[i]);
				combinationSum2(res, vec, candidates, target, sum, i+1); //ע��combination sumI�У����һ��������i,�����i+1
				sum -= vec.back(); //���ݵ���һ״̬����������ֵ
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