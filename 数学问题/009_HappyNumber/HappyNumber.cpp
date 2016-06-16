/* TITLE: Write an algorithm to determine if a number is "happy".A happy number is a number defined by the following process: 
 *		Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process
 *		until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers
 *		for which this process ends in 1 are happy numbers.
 *		Example: 19 is a happy number
 *		12 + 92 = 82
 *		82 + 22 = 68
 *		62 + 82 = 100
 *		12 + 02 + 02 = 1
 *
 * TIME:2015-5-7
 * FROME:leetcode
 */
#include <iostream>
#include <hash_map> //��Щ�ط���һ��֧��
using namespace std;

/* ��Ŀ�и����������һ��������happy���������ж���һ����ѭ���������ǵ��㷨��������ѭ��
 * ���ַ�happy���Ĺ����Ǽ���������һ��ѭ������ô�Ϳ����ж��Ƿ����������ѭ����
 * ʹ��hash��
 */
class Solution {
public:
	bool isHappy(int n) {
		hash_map<int, bool>::iterator it;
		while (n != 1){
			n = SumOfSquares(n);
			it = hm.find(n); //���ң����ص�����
			if (it == hm.end())// end() returns a bidirectional iterator that points just beyond the end of the controlled sequence.
				hm.insert(pair<int, bool>(n, true)); //��������pair��ʽ����ģ����Բ鿴hash_mapʵ�֣�
			else
				return false;
		}
		return true;
	}

private:
	int SumOfSquares(int n)
	{
		int sum = 0;
		int digit;
		while (n){
			digit = n % 10;
			n /= 10;
			sum += digit*digit;
		}
		return sum;
	}
	hash_map<int, bool> hm;
};

int main()
{
	Solution s;
	//cout << s.SumOfSquares(19) << endl;
	//cout << s.isHappy(1) << endl;
	//cout << s.isHappy(21) << endl;
	cout << s.isHappy(2) << endl;
	system("pause");
}