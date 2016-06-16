/* TITLE：Climbing Stair
 * 		You are climbing a stair case. It takes n steps to reach to the top.
 * 		Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * TIME:2015-5-8
 * FROM:leetcode
 * TYPE:DP
 */
#include <iostream>
using namespace std;

/* 本质上是Fibonacii数列
 */
class Solution {
public:
	int climbStairs(int n) {
		int ways = 0;
		if (n <= 0)
			return 0;
		else if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else{
			int a = 1, b = 2;
			for (int i = 3; i <= n; i++){
				ways = a + b;
				a = b;
				b = ways;
			}
			return ways;
		}
	}
};

int main()
{
	Solution s;
//	int n = 3;
//	int n = 4;
	int n = 5;
	cout << s.climbStairs(2) << endl;
	system("pause");
}