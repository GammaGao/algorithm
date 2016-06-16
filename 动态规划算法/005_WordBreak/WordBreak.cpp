/* TITLE:Word Break
 *		Given a string s and a dictionary of words dict, determine 
 *		if s can be segmented into a space-separated sequence of one
 *		or more dictionary words. 
 *		For example, given
 *		s = "leetcode",
 *		dict = ["leet", "code"]. 
 *		Return true because "leetcode" can be segmented as "leet code". 
 * 
 * TIME:2015-5-10
 * FROM:leetcode
 * TYPE:DP
 */
#include <iostream>
#include <unordered_set>
using namespace std;

/* 思路：动态规划算法，如：s="leetcode"，wordDict = ["leet", "code"]，定义两个指针i和j，指向s,
 *		当i指向l时，比较j-i之间的组的所符串是否在wordDict内（j--直到i）。用bool res[len+1]表示是否可分解
 *		res[0] = true; //总是如此
 *		res[1] = res[0] && <j,i>子串是否在WordDict内
 * 性能：unorded_set容器的查找时间复杂度是O(1)。 设s长度为m, 在最坏情况下, 在unorded_set容器中查找子串次数为
 *		1+2+3...+n=n(n-1)/2, 故时间复杂为O(n^2)。
 */
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();
		bool *res = new bool[len+1];
		unordered_set<string>::const_iterator it;

		if (s.length() == 0 || wordDict.size() == 0)
			return false;
		res[0] = true; //始终为true
		for (int i = 1; i < len+1; i++) //剩余为false，真正状态的表示从1开始
			res[i] = false;
		for (int i = 0; i < s.length(); i++){ //遍历
			for (int j = 0; j <= i; ++j) { //j-i组成的子串
				string sub = s.substr(j, i+1-j); //获取所有子串substr(pos, size_of_len)
				it = wordDict.find(sub); //查找是否存在子串
				if (it != wordDict.end()) { //找到子串
					res[i+1] = res[j] && true; //res从1开始表示真实情情况
					if (res[i+1])
						break;
				}
			}
		}
		return res[len];
	}
};

int main()
{
	string s1 = "leetbcode";
	unordered_set<string> wordDict1 = { "leet", "code", "b"};
	string s2 = "abcd";
	unordered_set<string> wordDict2 = { "a", "abc", "b", "cd" };
	string s3 = "aaaaaaa";
	unordered_set<string> wordDict3 = { "aaaa", "aaa" };
	string s4 = "a";
	unordered_set<string> wordDict4 = { "b" };
	string s5 = "dogs";
	unordered_set<string> wordDict5 = { "dog", "s", "gs"};
	Solution sl;
	cout << sl.wordBreak(s1, wordDict1) << endl;
	cout << sl.wordBreak(s2, wordDict2) << endl;
	cout << sl.wordBreak(s3, wordDict3) << endl;
	cout << sl.wordBreak(s4, wordDict4) << endl;
	cout << sl.wordBreak(s5, wordDict5) << endl;
	system("pause");
}