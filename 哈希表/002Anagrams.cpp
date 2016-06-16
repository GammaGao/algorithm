#include <iostream>
#include <algorithm>
#include <vector>
/* @TITLE: Anagrams(变位词)
 *		Given an array of strings, return all groups of strings that are anagrams.
 *		Note: All inputs will be in lower-case.
 *		如："ate" "tae"就是变位词，即只是改变位置顺序
 * @TIME:2015-6-29
 * @TYPE:哈希表
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string> res;
		unordered_map<string, int> hmap;
		for (int i = 0; i < strs.size(); i++){
			string s = strs[i];
			sort(s.begin(), s.end());
			//unordered_map<string, int>::iterator it = hmap.find(s);
			auto it = hmap.find(s); //it->first即key, it->second即val, 
			//auto自动类型推断，用于从初始化表达式中推断出变量的数据类型(C++ 11特性)

			if (it != hmap.end()){
				if (it->second != -1){
					res.push_back(strs[it->second]); //插入第一个值
					it->second = -1; //作一下标记，不让其插入重复值
				}
				res.push_back(strs[i]);
			}
			else
				hmap[s] = i; //注意, 这种方法是哈希表中不存在s时，会自动插入
		}
		return res;
	}
};

int main()
{
	Solution sl;
	vector<string> strs = { "tea", "and", "ate", "eat", "dan" };
	vector<string> res;
	res = sl.anagrams(strs);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	system("pause");
}