/* TITLE: Decode Ways
 *		A message containing letters from A-Z is being encoded to numbers using the following mapping: 
		'A' -> 1
		'B' -> 2
		...
		'Z' -> 26
 *		Given an encoded message containing digits, determine the total number of ways to decode it. 
 *		For example,
 *		Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 
 *		The number of ways decoding "12" is 2. 
 *
 * TIME:2015-5-12
 * TYPE:DP
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <string>
using namespace std;

/* 动态规划解决这个问题非常容易，用迭代法实现，时间复杂度O(n)
 * 给定一个字符串，"123", f(n)为字符串长为n的解码方式, f(3) = f(2)+f(1),当"23"可解码成一个字符W, 2和3又可分开解码
 * 给定一个字符串，"134", f(3) = f(2), 因为34不能解成一个字符
 */
class Solution {
public:
	int numDecodings(string s) {
		int f0 = 1, f1 = 1, f2 =0;
		if (!IsValidEncodedMessage(s))
			return 0;
		if (s.length() == 1)
			return 1;
		for (int i = 1; i < s.length(); i++){
			//当前字符只能单独解码，不能跟前面合在一起解码的情况
			if (s[i-1] == '0' || s[i - 1] > '2' || (s[i - 1] == '2' && s[i] > '6'))
				f2 = f1;
			else if (s[i] == '0') //s is already a vaild encoded messages.
				f2 = f0; //当前字符为'0'，只能跟前面的字符组成一起合成一个合法字符 
			else{
				f2 = f1 + f0;
			}
			f0 = f1; //迭代
			f1 = f2;
		}
		return f2;
	}
private:
	/* 判断一个字符串是否是合法的编码数字字符串 */
	bool IsValidEncodedMessage(string &s)
	{
		int i = 0;
		if (s.length() == 0) //空串不合法
			return false;
		if (s[i++] == '0') //s[0]为0的数字字符串肯定不合法
			return false;
		while (i < s.length() && s[i] >= '0' && s[i] <= '9'){
			//如果当前字符为0，那么前面的字符只能是1或2，否则肯定不合法
			if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))
				break;
			i++;
		}
		if (i != s.length())
			return false;
		return true;
	}
};

int main()
{
	Solution sl;
	//string  s = "1110"; //KJ
	//string  s = "0"; //Invaild
	//string s = "10"; //J
	//string s = "101"; //JA

	cout << sl.numDecodings(s) << endl;
	system("pause");
}