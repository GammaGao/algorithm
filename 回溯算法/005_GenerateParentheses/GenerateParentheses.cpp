/* TITLE: Generate Parentheses
 *		Given n pairs of parentheses, write a function to generate
 *		all combinations of well-formed parentheses. For example, given n = 3, a solution set is:
 *		"((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * TYPE:回溯算法
 * TIME:2015-5-20
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string parenthesis;
		generateParenthesis(res, n, n, parenthesis);
		return res;
	}
private:
	//其中的left和right数表示"("和")"的数
	void generateParenthesis(vector<string> &res, int left, int right, string &parenthesis)
	{
		if (left == 0 && right == 0)
			res.push_back(parenthesis);
		if (left > 0){
			//parenthesis.push_back('(');
			//generateParenthesis(res, left - 1, right, parenthesis);
			//parenthesis.pop_back();
			//使用上述方式可能更明显的表示回溯，下面的方式是等效的
			generateParenthesis(res, left - 1, right, parenthesis+"(");
		}
		//right > left表示只有parenthesis前面有"("的情况下才进入")"
		if (right > 0 && right > left){
			//parenthesis.push_back(')');
			//generateParenthesis(res, left, right - 1, parenthesis);
			//parenthesis.pop_back();

			generateParenthesis(res, left, right - 1, parenthesis+")");
		}
	}
};

int main()
{
	Solution sl;
	vector<string> res;
	res = sl.generateParenthesis(3);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	system("pause");
}