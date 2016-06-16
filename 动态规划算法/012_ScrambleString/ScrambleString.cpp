/* TITLE: Scramble String 
 *		Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
 *		Below is one possible representation of s1 = "great":
			great
			/ \
		  gr   eat
		 / \ / \
		g  r e  at
				/ \
			   a   t
 *
 * To scramble the string, we may choose any non - leaf node and swap its two children.
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
		   rgeat
			/ \
		  rg    eat
		  / \ / \
		 r  g e  at
		         / \
			    a   t
 * We say that "rgeat" is a scrambled string of "great".
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
		   rgtae
			/ \
		   rg tae
		   / \ / \
		  r   g  ta  e
			    / \
			   t   a
 * We say that "rgtae" is a scrambled string of "great".
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 * NOET: "great" is also a scramble string of "great".
 *
 * TIME:2015-5-14
 * FROM:leetcode
 * TYPE:DP
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* 递归实现, 这个问题并不是判断这两个字符串是否是相同组成的不同排列
 * 如："bdac"并不是"abcd"的一个scramble string
 */
class Solution_1 {
public:
	bool isScramble(string s1, string s2) {
		int n = s1.length();
		return judge(s1.c_str(), s2.c_str(), 0, n - 1, 0, n - 1);
	}

private:
	bool judge(const char* s1, const char* s2, int a, int b, int u, int v){
		if (b - a != v - u) return false;
		if (b - a == 0 && s1[a] == s2[u]) return true;

		int cnt[256] = { 0 };
		for (int i = a; i <= b; ++i){
			cnt[s1[i]]++;
		}
		for (int i = u; i <= v; ++i){
			cnt[s2[i]]--;
		}
		for (int i = 0; i<256; ++i){
			if (cnt[i] != 0) return false;
		}

		for (int i = a; i<b; ++i){
			if (judge(s1, s2, a, i, u, u + i - a) && judge(s1, s2, i + 1, b, v - (b - i - 1), v)){
				return true;
			}
			if (judge(s1, s2, a, i, v - (i - a), v) && judge(s1, s2, i + 1, b, u, u + b - (i + 1))){
				return true;
			}
		}
		return false;
	}
};

class Solution{
public:
	bool isScramble(string s1, string s2) {
		vector<int> count(256, 0);
		for (int i = 0; i < s1.length(); i++)
			count[s1[i]]++;
		for (int j = 0; j < s2.length(); j++)
			count[s2[j]]--;
		for (int i = 0; i < count.size(); i++){
			if (count[i] != 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution sl;
	cout << sl.isScramble("great", "rgeat") << endl;
	cout << sl.isScramble("great", "rgtae") << endl;
	cout << sl.isScramble("great", "taerg") << endl;
	cout << sl.isScramble("great", "greta") << endl;
	cout << sl.isScramble("great", "great") << endl;
	cout << sl.isScramble("abc", "bca") << endl;
	cout << sl.isScramble("abcdef", "fedbca") << endl;
	system("pause");
}