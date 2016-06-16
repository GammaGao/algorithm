/* TITLE: Generate Parentheses
 *		Given n pairs of parentheses, write a function to generate
 *		all combinations of well-formed parentheses. For example, given n = 3, a solution set is:
 *		"((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * TYPE:�����㷨
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
	//���е�left��right����ʾ"("��")"����
	void generateParenthesis(vector<string> &res, int left, int right, string &parenthesis)
	{
		if (left == 0 && right == 0)
			res.push_back(parenthesis);
		if (left > 0){
			//parenthesis.push_back('(');
			//generateParenthesis(res, left - 1, right, parenthesis);
			//parenthesis.pop_back();
			//ʹ��������ʽ���ܸ����Եı�ʾ���ݣ�����ķ�ʽ�ǵ�Ч��
			generateParenthesis(res, left - 1, right, parenthesis+"(");
		}
		//right > left��ʾֻ��parenthesisǰ����"("������²Ž���")"
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