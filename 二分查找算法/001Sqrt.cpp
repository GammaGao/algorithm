/* TITLE: Sqrt(x) 
 *		Implement int sqrt(int x). Compute and return the square root of x.
 *
 * TIME:2015-5-14
 * FROM:leetcode
 * TYPE:binary search
 * AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

/* ���ֲ��ң�ʵ����������ƽ����������ȡ����
 * ���ܣ�ʱ�临�Ӷ�O(logn)
 */
class Solution {
public:
	int mySqrt(int x) {
		int p = 1, q = x;
		int root;
		if (x <= 0)
			return 0;
		while (p <= q){
			root = ((unsigned long long)p + q) / 2; //�ǳ�ע���м����ĵ�Խ��
			if ((unsigned long long)root * root == x ||
				(unsigned long long)root*root < x && (unsigned long long)(root + 1)*(root + 1) > x)
				return root;
			else if ((unsigned long long)root * root > x)
				q = root - 1;
			else
				p = root + 1;
		}
		return p;
	}
};

int main()
{
	Solution sl;
	for (int i = 0; i < 100; i++)
		cout << i << "'s root is " << sl.mySqrt(i)<< endl;
	cout << sl.mySqrt(2147395599) << endl;
	cout << sl.mySqrt(2147483647) << endl; //INT_MAX
	system("pause");
}