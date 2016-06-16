/* @TITLE: Restore IP Addresses
 *		Given a string containing only digits, restore it by returning all possible valid IP address combinations.
		For example:
		Given "25525511135",
		return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 * @TIME:2015-5-22
 * @TYPE:backtracking
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

/* 回溯某种程度上与递归很好的结合在一起
 * c_str()把string类型转换成C风格字符串指针， atoi把char*指针转换成int
 */
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string ip;
		help(res, ip, s, 0, 4); //4代表点分十进制的四部分
		return res;
	}

private:
	void help(vector<string> &res, string ip, string &s, int start, int num)
	{
		int numDigits = s.size() - start;
		if (numDigits < num || numDigits > 3 * num)//最大限度限制不合法输入
			return;
		if (num == 1){ //点分十进制最后一部分的数
			if (numDigits == 1 || (s[start] != '0' && atoi(s.substr(start).c_str()) <= 255))
				res.push_back(ip + s.substr(start));
		}
		else{
			help(res, ip + s.substr(start, 1) + ".", s, start + 1, num - 1); //一个数构成一部分

			if (s[start] != '0'){// && atoi(s.substr(start, 2).c_str()) <= 255){
				// two numbers must be smaller than 255, no need do this.
				help(res, ip + s.substr(start, 2) + ".", s, start + 2, num - 1); //两个数构造一分部
			}
			if (s[start] != '0' && atoi(s.substr(start, 3).c_str()) <= 255){
				help(res, ip + s.substr(start, 3) + ".", s, start + 3, num - 1); //三个数构造一部分
			}
		}
	}
};

int main()
{
	Solution sl;
	//string s = "25525511135"; //255.255.11.135, 255.255.111.35
	string s = "1921683110";
	//string s = "0000";
	//string s = "11111111111111111111111111111111";
	//string s = "010010";
	vector<string> res;
	res = sl.restoreIpAddresses(s);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
}