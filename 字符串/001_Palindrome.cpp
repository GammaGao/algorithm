/* TITLE: Valid Palindrome（有效回文串）
 *		Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *		For example,
 *		"A man, a plan, a canal: Panama" is a palindrome.
 *		"race a car" is not a palindrome.
 *
 * TIME:2015-5-8
 * FROM:leetcode
 */
#include <iostream>
#include <string>
using namespace std;

/* 思路简单，头尾同时处理
 */
class Solution {
public:
	bool isPalindrome(string s) {
		int start, end;
		start = 0;
		end = s.length() - 1;
		while (start < end){
			while (start < end && !isAlphanumeric(s.at(start)))//跳过头部无效字符
				start++;
			while (start < end && !isAlphanumeric(s.at(end)))//跳过尾部无效字符
				end--;
			if (start < end && !isEqualAlphanumeric(s.at(start), s.at(end)))
				return false;
			start++;
			end--;
		}
		return true;
	}
private:
	/* 判断一个字符是否是数字字符 */
	bool isAlphanumeric(char c)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
			return true;
		else
			return false;
	}
	/* 判断两个数字字符是否相等，忽略大小写 */
	bool isEqualAlphanumeric(char a, char b)
	{
		if (a == b || a == b - 32 || a == b + 32)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
//	string in = "A man, a plan, a canal: Panama";
//	string in = "";
	string in = "race a car";
	//cout << s.isEqualAlphanumeric('A', 'b') << endl;
	cout << s.isPalindrome(in) << endl;
	system("pause");
}