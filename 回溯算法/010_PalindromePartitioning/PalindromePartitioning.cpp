/* @TITLE:Palindrome Partitioning
 *		Given a string s, partition s such that every substring of the partition is a palindrome.
 *		Return all possible palindrome partitioning of s.
 *		For example, given s = "aab",
		Return
		  [
			["aa","b"],
			["a","a","b"]
		  ]
 *
 * @TIME:2015-5-23
 * @TYPE:backtracking
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 回溯算法
 */
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> tmp;
		partition(res, s, tmp, 0);
		return res;
	}

private:
	void partition(vector<vector<string>> &res, string &s, vector<string> &tmp, int start)
	{
		if (start == s.size()){
			res.push_back(tmp);
			return;
		}
		for (int i = start; i < s.size(); i++){
			if (isPalindrome(s.substr(start, i - start + 1))) {
				tmp.push_back(s.substr(start, i - start + 1));
				partition(res, s, tmp, i + 1);
				tmp.pop_back();
			}
		}
	}
	/* NOTE: C++临时变量作为const &传递是可以的，但作为非const引用是不行的（g++中无法编译过去，VS2013可以）
	 * 判断字符串是否是回文串
	 */
	bool isPalindrome(const string &s)
	{
		int p = 0, q = s.size() - 1;
		while (p < q && s[p] == s[q]){
			p++; q--;
		}
		if (p >= q)
			return true;
		return false;
	}
};

int main()
{
	Solution sl;
	vector<vector<string>> res;
	//string s = "123321";
	//cout << sl.isPalindrome(s) << endl;

	string s = "aabcb";
	res = sl.partition(s);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}