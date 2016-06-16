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
* TYPE:backtrace(�����㷨)
* AUTHOR:PengSc
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* ��ͨ������{1,2��3}�Ȱѵ�һ��ɨ��ÿһ�������Ȱѿռ������������ٰ�1����������
*		�ڶ���ɨ�裬�ٰ�����ǰ���������������2������ӵ�����β����
* ���ܣ�ʱ�临�Ӷ�O(2^n),��Ϊ�Ӽ�����Ϊ2^n����
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
				v = ret[j]; //ȡ��֮ǰ��
				v.push_back(nums[i]); //��ÿ�������������
				ret.push_back(v); //����ӵ������ȥ
			}
		}
		return ret;
	}
};

/* �����㷨�����ݲ�����ָ�ݹ飬����һ�����˼·��һ��ϵͳϵͳ����������ķ�����
*		�ȷ��ʿռ�[], �ٷ���1���ٻ�����[],�ٷ���2,�ٻ���,�ٷ���3�����е�ÿһ�����Կ���һ���ӹ��̡�
*		����ʵ�1ʱ���ɻ���Ҳ������ȷ��ʡ����������£������Tire������
		[ ] //�ռ�
		/      |    \
		[1]     [2]    [3]
		/  \      /
		[1,2] [1,3] [2,3]
		/
		[1,2,3]
* �����㷨�ĵ���Ӧ�ã��ݼ����⣨���⣩��ͼ���Թ����⣩�����������������Ͼ��ǻ��ݣ�
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
			vec.pop_back(); //��������״̬
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