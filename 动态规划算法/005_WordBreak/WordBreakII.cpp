/* TITLE: Word Break II
 *		Given a string s and a dictionary of words dict, add spaces in s to construct
 *		a sentence where each word is a valid dictionary word. Return all such possible
 *		sentences. For example, given s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"]. 
 *		A solution is ["cats and dog", "cat sand dog"]. 
 *
 * TIME:2015-5-13
 * FROM:leetcode
 * TYPE:DP
 * AUTHOR:PengSc
 */
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/* ˼·�������㷨���ݹ�ʵ��
 */
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> res;
		if (s.length() == 0 || wordDict.size() == 0) //�ǺϷ�����
			return res;
		if (!IswordBreak(s, wordDict)) //���ж��Ƿ�ɷֽ⣬��ʵ�ⲽ��
			return res;
		return __wordBreak(s, wordDict); //�ֽ�
	}
private:
	/* unordered_set�����򼯺��������洢ΨһԪ�أ�����ֵ���п��ٵĹ�ϣ���� */
	vector<string> __wordBreak(string &sub, unordered_set<string> &wordDict)
	{
		vector<string> res;
		if (sub.length() == 0)
			return res;
		for (int i = 0; i < sub.length(); i++){
			//find/count�������ڲ���Ԫ���Ƿ���ڣ�����ֵ��ͬ�� substr(pos, len), ����ֻ��һ������ʱ����ʾ�ӵ�ǰλ�õ������������ַ���
			if (wordDict.count(sub.substr(0, i + 1)) == 1){
				vector<string> tmp = wordBreak(sub.substr(i + 1), wordDict);
				if (tmp.size() == 0 && i+1 == sub.length()) //�Ƿ������Ŀɷֽ��ַ������������ַ������ɷֽ�
					res.push_back(sub.substr(0, i + 1));
				for (int j = 0; j < tmp.size(); j++)
					res.push_back(sub.substr(0, i + 1) + " " + tmp[j]);
			}
		}
		return res;
	}
public:
	bool IswordBreak(string &sub, unordered_set<string> &wordDict)
	{
		bool *isBreak = new bool[sub.length()+1];
		isBreak[0] = true; //virtual, always true;
		for (int i = 1; i < sub.length() + 1; i++)
			isBreak[i] = false;
		for (int i = 0; i < sub.length(); i++){
			for (int j = 0; j <= i; j++){
				if (wordDict.count(sub.substr(j, i + 1 - j)) == 1 && isBreak[j] == true){
					isBreak[i+1] = true;
					break;
				}
			}
		}
		return isBreak[sub.length()];
	}
};

class Solution_1 {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		return wordBreak(s, wordDict, 0);
	}
private:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict, int start)
	{
		vector<string> res;
		if (s.length() == 0 || wordDict.size() == 0){
			return res;
		}
		else{
			vector<string> tmp;
			unordered_set<string>::iterator it;;
			string sub;
			for (int i = start; i < s.length(); i++){
				sub = s.substr(start, i + 1 - start);
				it = wordDict.find(sub);
				if (it != wordDict.end()){
					if (i == s.length() - 1)
						res.push_back(sub);
					else{
						tmp = wordBreak(s, wordDict, i + 1);
						for (int j = 0; j < tmp.size(); j++){
							res.push_back(sub + " " + tmp.at(j));
						}
					}
				}
				else if (i == s.length() - 1)
					return res;
			}
			return res;
		}
	}
};

int main()
{
	string s = "catsanddog";
	unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog"};

	string s1 = "leetcodeleet";
	unordered_set<string> wordDict1 = {"leet", "code"};

	//string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//string s2 = "aaaaaaaaaa"; //10
	string s2 = "aaaaaaaaaaaaaaa"; //15����������5s����
	//string s2 = "aaaaaaaaaaaaaaaaaaaa"; //20
	unordered_set<string> wordDict2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };

	string s3 = "abcd";
	unordered_set<string> wordDict3 = {"a", "abc", "b", "cd"};
	vector<string> res;
	Solution sl;
	cout << sl.IswordBreak(s, wordDict) << endl;
	cout << sl.IswordBreak(s1, wordDict1) << endl;
	cout << sl.IswordBreak(s2, wordDict2) << endl;
	res = sl.wordBreak(s, wordDict);
	for (int i = 0; i < res.size(); i++){
		cout << res.at(i).length() << ",";
		cout << res.at(i) << endl;
	}

	res = sl.wordBreak(s1, wordDict1);
	for (int i = 0; i < res.size(); i++){
		cout << res.at(i).length() << ",";
		cout << res.at(i) << endl;
	}

	res = sl.wordBreak(s2, wordDict2);
	for (int i = 0; i < res.size(); i++){
		cout << res.at(i).length() << ",";
		cout << res.at(i) << endl;
	}

	res = sl.wordBreak(s3, wordDict3);
	for (int i = 0; i < res.size(); i++){
		cout << res.at(i).length() << ",";
		cout << res.at(i) << endl;
	}
	system("pause");
}