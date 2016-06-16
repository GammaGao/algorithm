/* TITLE: Letter Combinations of a Phone Number
 *		Given a digit string, return all possible letter combinations that the number could represent.
 *		A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
			1|	2|	3
			----------
			4|	5|	6
			----------
			7|	8|	9
 * 0-9 -> {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
 * 
 * TIME:2015-5-21
 * TYPE:backtracking
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 回溯
 */
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		/* digital key board mapping letter */
		vector<string> letter = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res;
		string s;
		help(res, digits, s, 0, letter);
		return res;
	}
private:
	void help(vector<string> &res, string &digits, string &s, int start, vector<string> &letter)
	{
		if (start == digits.size())
			return;

		for (int i = 0; i < letter[digits[start]-'0'].size(); i++){ //每个数字映射的字母个数都不同
			s.push_back(letter[digits[start]-'0'][i]);
			help(res, digits, s, start + 1, letter);
			if (start == digits.size() - 1)
				res.push_back(s);
			s.pop_back();
		}
	}
};

int main()
{
	Solution sl;
	vector<string> res;
	res = sl.letterCombinations("23");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
}