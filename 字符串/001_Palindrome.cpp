/* TITLE: Valid Palindrome����Ч���Ĵ���
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

/* ˼·�򵥣�ͷβͬʱ����
 */
class Solution {
public:
	bool isPalindrome(string s) {
		int start, end;
		start = 0;
		end = s.length() - 1;
		while (start < end){
			while (start < end && !isAlphanumeric(s.at(start)))//����ͷ����Ч�ַ�
				start++;
			while (start < end && !isAlphanumeric(s.at(end)))//����β����Ч�ַ�
				end--;
			if (start < end && !isEqualAlphanumeric(s.at(start), s.at(end)))
				return false;
			start++;
			end--;
		}
		return true;
	}
private:
	/* �ж�һ���ַ��Ƿ��������ַ� */
	bool isAlphanumeric(char c)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
			return true;
		else
			return false;
	}
	/* �ж����������ַ��Ƿ���ȣ����Դ�Сд */
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