/* TITLE: Combinations
 *		Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *		For example,
 *		If n = 4 and k = 2, a solution is:
		[
		  [2,4],
		  [3,4],
		  [2,3],
		  [1,2],
		  [1,3],
		  [1,4],
		]
 *
 * TYPE:ªÿÀ›À„∑®
 * TIME:2015-5-20
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> vec;
		int depth = 0;
		if (k < 0 || k > n)
			return res;
		combine(res, vec, n, k, 1, depth);
		return res;
	}

private:
	void combine(vector<vector<int>> &res, vector<int>&vec, int n, int k, int start, int &depth)
	{
		for (int i = start; i <= n; i++){
			depth++;
			if (depth == k){
				vec.push_back(i);
				res.push_back(vec);
				vec.pop_back();
				depth--;
			}
			else if (depth < k){
				vec.push_back(i);
				combine(res, vec, n, k, i+1, depth);
				vec.pop_back();
				depth--;
			}
			else{ //if (dep > k) this will never happen.
				return;
			}
		}
	}
};

int main()
{
	Solution sl;
	vector<vector<int>> res;
	res = sl.combine(1, 1);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res.at(i).size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}