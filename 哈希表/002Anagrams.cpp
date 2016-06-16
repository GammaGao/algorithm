#include <iostream>
#include <algorithm>
#include <vector>
/* @TITLE: Anagrams(��λ��)
 *		Given an array of strings, return all groups of strings that are anagrams.
 *		Note: All inputs will be in lower-case.
 *		�磺"ate" "tae"���Ǳ�λ�ʣ���ֻ�Ǹı�λ��˳��
 * @TIME:2015-6-29
 * @TYPE:��ϣ��
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
			auto it = hmap.find(s); //it->first��key, it->second��val, 
			//auto�Զ������ƶϣ����ڴӳ�ʼ�����ʽ���ƶϳ���������������(C++ 11����)

			if (it != hmap.end()){
				if (it->second != -1){
					res.push_back(strs[it->second]); //�����һ��ֵ
					it->second = -1; //��һ�±�ǣ�����������ظ�ֵ
				}
				res.push_back(strs[i]);
			}
			else
				hmap[s] = i; //ע��, ���ַ����ǹ�ϣ���в�����sʱ�����Զ�����
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