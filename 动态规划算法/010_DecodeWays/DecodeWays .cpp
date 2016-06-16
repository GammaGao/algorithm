/* TITLE: Decode Ways
 *		A message containing letters from A-Z is being encoded to numbers using the following mapping: 
		'A' -> 1
		'B' -> 2
		...
		'Z' -> 26
 *		Given an encoded message containing digits, determine the total number of ways to decode it. 
 *		For example,
 *		Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 
 *		The number of ways decoding "12" is 2. 
 *
 * TIME:2015-5-12
 * TYPE:DP
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
#include <string>
using namespace std;

/* ��̬�滮����������ǳ����ף��õ�����ʵ�֣�ʱ�临�Ӷ�O(n)
 * ����һ���ַ�����"123", f(n)Ϊ�ַ�����Ϊn�Ľ��뷽ʽ, f(3) = f(2)+f(1),��"23"�ɽ����һ���ַ�W, 2��3�ֿɷֿ�����
 * ����һ���ַ�����"134", f(3) = f(2), ��Ϊ34���ܽ��һ���ַ�
 */
class Solution {
public:
	int numDecodings(string s) {
		int f0 = 1, f1 = 1, f2 =0;
		if (!IsValidEncodedMessage(s))
			return 0;
		if (s.length() == 1)
			return 1;
		for (int i = 1; i < s.length(); i++){
			//��ǰ�ַ�ֻ�ܵ������룬���ܸ�ǰ�����һ���������
			if (s[i-1] == '0' || s[i - 1] > '2' || (s[i - 1] == '2' && s[i] > '6'))
				f2 = f1;
			else if (s[i] == '0') //s is already a vaild encoded messages.
				f2 = f0; //��ǰ�ַ�Ϊ'0'��ֻ�ܸ�ǰ����ַ����һ��ϳ�һ���Ϸ��ַ� 
			else{
				f2 = f1 + f0;
			}
			f0 = f1; //����
			f1 = f2;
		}
		return f2;
	}
private:
	/* �ж�һ���ַ����Ƿ��ǺϷ��ı��������ַ��� */
	bool IsValidEncodedMessage(string &s)
	{
		int i = 0;
		if (s.length() == 0) //�մ����Ϸ�
			return false;
		if (s[i++] == '0') //s[0]Ϊ0�������ַ����϶����Ϸ�
			return false;
		while (i < s.length() && s[i] >= '0' && s[i] <= '9'){
			//�����ǰ�ַ�Ϊ0����ôǰ����ַ�ֻ����1��2������϶����Ϸ�
			if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))
				break;
			i++;
		}
		if (i != s.length())
			return false;
		return true;
	}
};

int main()
{
	Solution sl;
	//string  s = "1110"; //KJ
	//string  s = "0"; //Invaild
	//string s = "10"; //J
	//string s = "101"; //JA

	cout << sl.numDecodings(s) << endl;
	system("pause");
}