/* @TITLE: Combination Sum III
 *		Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *		Ensure that numbers within the set are sorted in ascending order.
 *		Example 1:
 *		Input: k = 3, n = 7
 *		Output:
 *		[[1,2,4]]
 *		Example 2:
 *		Input: k = 3, n = 9
 *		Output:
 *		[[1,2,6], [1,3,5], [2,3,4]]
 *
 * @TIME:2015-5-24
 * @TYPE:backtracking
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* Ë¼Â·£º»ØËÝÌ½²â
 */
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>>res;
		vector<int> tmp;
		int sum = 0;
		combinationSum3(res, k, n, sum, tmp, 1);
		return res;
	}
private:
	void combinationSum3(vector<vector<int>>&res, int k, int n, int sum, vector<int> tmp, int start)
	{
		if (tmp.size() == k && sum == n){
			res.push_back(tmp);
			return;
		}
		if (start == 10 || tmp.size() > k)
			return;
		for (int i = start; i <= 9; i++){
			sum += i;
			if (sum > n)
				return;
			else if (sum <= n){
				tmp.push_back(i);
				combinationSum3(res, k, n, sum, tmp, i+1);
				tmp.pop_back();
				sum -= i;
			}
		}
	}
};

int main()
{
	Solution sl;
	vector<vector<int>>res;
	res = sl.combinationSum3(1,9); //0
	//res = sl.combinationSum3(9, 45); //1-9
	//res = sl.combinationSum3(9, 46); //null
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}