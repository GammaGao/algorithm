/* TITLE: Given two strings s and t, determine if they are isomorphic(同构的，同形的).
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

/* 判断两个字符串
 * 时间复杂度O(n)
 * 使用两个hash_map表，分别存储字符串s->t和t->s的映射，检查映射关系是否满足两个不同字符不能被映射到同一字符，
 * 相同的字符可以映射到同一字符上。
 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		string::iterator its, itt;
		hash_map<char, char>::iterator hits;
		hash_map<char, char>::iterator hitt;
		for (its = s.begin(), itt = t.begin(); its != s.end() && itt != t.end(); its++, itt++){
			hits = hms.find(*its); //find()返回对应key位置的迭代器
			hitt = hmt.find(*itt); 
			if (hits == hms.end()) //如果没找到该元素，迭代器指向是超过边界的后一位置
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