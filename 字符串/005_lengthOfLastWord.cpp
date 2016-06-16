/* 题目：Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0. Note: A word is defined as a character sequence consists of non-space characters only. 
 * For example, Given s = "Hello World", return 5.
 * TIME：2015-5-7
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		int i = s.length() - 1;
		while (i >= 0 && s[i] == ' ') //从尾往处理，先跳过空格
			i--;
		while (i >= 0 && isAlphabet(s[i])){
			count++;
			i--;
		}
		return count;
	}
	bool isAlphabet(char c)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			return true;
		else
			return false;
	}
};

int main()
{
	//string t = "hello world";
	//string t = "hell  worldxx  ";
	//string t = "";
	//string t = " ";
	string t = "xxxx   a ccc    ";
	Solution s;
	cout << s.lengthOfLastWord(t) << endl;
	system("pause");
}