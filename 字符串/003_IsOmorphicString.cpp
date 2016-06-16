/* TITLE: Given two strings s and t, determine if they are isomorphic(ͬ���ģ�ͬ�ε�).
 *		Two strings are isomorphic if the characters in s can be replaced to get t.
 *		All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
 *		For example,
 *		Given "egg", "add", return true.
 *		Given "foo", "bar", return false.
 *		Given "paper", "title", return true.
 *
 * TIME:2015-5-8
 * FROM:leetcode
 */
#include <iostream>
#include <hash_map>
using namespace std;

/* �ж������ַ���
 * ʱ�临�Ӷ�O(n)
 * ʹ������hash_map���ֱ�洢�ַ���s->t��t->s��ӳ�䣬���ӳ���ϵ�Ƿ�����������ͬ�ַ����ܱ�ӳ�䵽ͬһ�ַ���
 * ��ͬ���ַ�����ӳ�䵽ͬһ�ַ��ϡ�
 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		string::iterator its, itt;
		hash_map<char, char>::iterator hits;
		hash_map<char, char>::iterator hitt;
		for (its = s.begin(), itt = t.begin(); its != s.end() && itt != t.end(); its++, itt++){
			hits = hms.find(*its); //find()���ض�Ӧkeyλ�õĵ�����
			hitt = hmt.find(*itt); 
			if (hits == hms.end()) //���û�ҵ���Ԫ�أ�������ָ���ǳ����߽�ĺ�һλ��
				hms.insert(pair<char, char>(*its, *itt));
			if (hitt == hmt.end())
				hmt.insert(pair<char, char>(*itt, *its));
			if (hms.at(*its) != *itt || hmt.at(*itt) != *its)
				return false;
		}
		return true;
	}
private:
	hash_map<char, char> hms, hmt;
};

int main()
{
	Solution s;
	string a, b;
//	a = "egg", b = "add"; //ture
//	a = "foo", b = "bar"; //false
//	a = "paper", b = "title"; //true
//	a = "ab", b = "aa";
	a = "abc", b = "acd";

	cout << s.isIsomorphic(a, b) << endl;
	system("pause");
}