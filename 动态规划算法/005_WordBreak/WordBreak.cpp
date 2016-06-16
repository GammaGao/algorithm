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

/* ˼·����̬�滮�㷨���磺s="leetcode"��wordDict = ["leet", "code"]����������ָ��i��j��ָ��s,
 *		��iָ��lʱ���Ƚ�j-i֮�������������Ƿ���wordDict�ڣ�j--ֱ��i������bool res[len+1]��ʾ�Ƿ�ɷֽ�
 *		res[0] = true; //�������
 *		res[1] = res[0] && <j,i>�Ӵ��Ƿ���WordDict��
 * ���ܣ�unorded_set�����Ĳ���ʱ�临�Ӷ���O(1)�� ��s����Ϊm, ��������, ��unorded_set�����в����Ӵ�����Ϊ
 *		1+2+3...+n=n(n-1)/2, ��ʱ�临��ΪO(n^2)��
 */
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();
		bool *res = new bool[len+1];
		unordered_set<string>::const_iterator it;

		if (s.length() == 0 || wordDict.size() == 0)
			return false;
		res[0] = true; //ʼ��Ϊtrue
		for (int i = 1; i < len+1; i++) //ʣ��Ϊfalse������״̬�ı�ʾ��1��ʼ
			res[i] = false;
		for (int i = 0; i < s.length(); i++){ //����
			for (int j = 0; j <= i; ++j) { //j-i��ɵ��Ӵ�
				string sub = s.substr(j, i+1-j); //��ȡ�����Ӵ�substr(pos, size_of_len)
				it = wordDict.find(sub); //�����Ƿ�����Ӵ�
				if (it != wordDict.end()) { //�ҵ��Ӵ�
					res[i+1] = res[j] && true; //res��1��ʼ��ʾ��ʵ�����
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