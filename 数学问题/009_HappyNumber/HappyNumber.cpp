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
#include <hash_map> //有些地方不一定支持
using namespace std;

/* 题目中告诉我们如果一个数不是happy数，它是判断是一个死循环，但我们的算法不能是死循环
 * 发现非happy数的规律是计算结果会是一个循环，那么就可以判断是否存在这样的循环。
 * 使用hash表
 */
class Solution {
public:
	bool isHappy(int n) {
		hash_map<int, bool>::iterator it;
		while (n != 1){
			n = SumOfSquares(n);
			it = hm.find(n); //查找，返回迭代器
			if (it == hm.end())// end() returns a bidirectional iterator that points just beyond the end of the controlled sequence.
				hm.insert(pair<int, bool>(n, true)); //插入是以pair格式插入的（可以查看hash_map实现）
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