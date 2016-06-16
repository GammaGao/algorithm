/* TITLE: Unique Binary Search Trees 
 *		Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *		For example,
 *		Given n = 3, there are a total of 5 unique BST's. 
		1         3     3      2      1
		\       /     /      / \      \
			3     2     1      1   3      2
		/     /       \                 \
		2     1         2                 3
 *
 * TIME:2015-5-12
 * FROM:leetcode
 * AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

class Solution_1 {
public:
	int numTrees(int n) {
		return numTrees(n, 0, n - 1);
	}

private:
	int numTrees(int n, int start, int end)
	{
		if (n == 0 || start > end)
			return 0;
		else if (start == end)
			return 1;
		else{
			int count = 0;
			count += numTrees(n, start+1, end);
			for (int i = start+1; i < end; i++){
				count += numTrees(n, start + 1, i) * numTrees(n, i + 1, end);
			}
			count += numTrees(n, start, end - 1);
			return count;
		}
	}
};

/* 可以导出递推公式f(n) = f(0)*f(n-1)+f(1)*f(n-2)+...f(n-2)*f(1)+f(n-1)*f(0)
 * 这是卡塔兰数，卡塔兰数的一般公式为 C(n,2n)/（n+1），也可以
 * f(n)=(4n-2)/(n+1)*f(n-1)(n>1) f(0)=1
 */
class Solution {
public:
	int numTrees(int n) {
		//cantalan树
		//C(2n,n)/(n+1)
		long long ans = 1;
		for (int i = n + 1; i <= 2 * n; i++){
			ans = ans*i / (i - n);
		}
		return ans / (n + 1);
	}
};
int main()
{
	class Solution s;
	cout << s.numTrees(0) << endl;
	cout << s.numTrees(1) << endl;
	cout << s.numTrees(2) << endl;
	cout << s.numTrees(3) << endl;
	cout << s.numTrees(4) << endl;
	cout << s.numTrees(19) << endl; //1767263190递归运算好十几秒
	system("pause");
}