/* TITLE: Combination Sum(������)
 *		Given a set of candidate numbers (C) and a target number (T),
 *		find all unique combinations in C where the candidate numbers sums to T.
 *		The same repeated number may be chosen from C unlimited number of times.
 *
 *		Note:
 *		All numbers (including target) will be positive integers.
 *		Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
 *		The solution set must not contain duplicate combinations.
 *		For example, given candidate set 2,3,6,7 and target 7, 
 *		A solution set is: 
			[7] 
			[2, 2, 3]
 * TYPE:backtracking(����)
 * TIME:2015-5-19
 * AUTHOR:PengSc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* �����㷨:������ͣ����������������
 * �磺[2,3,6,7]��Ϊ���е�ÿ�����������޴��ظ���ʵ���ϻ��ݱ���˷���һ��������
 *						    []
					  /         \           \      \
					[2]			[3]		   [6]		[7]
				/  /   \  \     /  \  \     /  \     \
 			  [2] [3] [6] [7]  [3] [6] [7] [6] [7]   [7]
			...   ... ... ...  ... ... ... ... ...   ...
			  ����2����2��3,6,7�� 3����3,6,7��2ȥ������Ϊ��Ͳ������ظ�)
 * �����㷨����ɷ��ʵ�������ͼ��
 */
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;//���ս��
		vector<int> vec;
		int sum = 0;
		sort(candidates.begin(), candidates.end()); //���ź���
		combinationSum(res, vec, candidates, target, sum, 0);
		return res;
	}

private:
	void combinationSum(vector<vector<int>>&res, vector<int> &vec, 
		vector<int> &candidates, int target, int &sum, int start)
	{
		for (int i = start; i < candidates.size(); i++){
			sum += candidates[i];
			if (sum == target){ //�ҵ�����Ҫ���������һ����
				vec.push_back(candidates[i]);
				res.push_back(vec); //��¼

				sum -= vec.back(); //���ݵ���һ״̬��������������Ҫ���ֵ
				vec.pop_back();
				return;
			}
			else if (sum < target){
				vec.push_back(candidates[i]);
				combinationSum(res, vec, candidates, target, sum, i);
				sum -= vec.back(); //���ݵ���һ״̬����������ֵ
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