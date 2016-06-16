/* TITLE: Count the number of prime numbers less than(小于) a non - negative number, n
 * 
 * TIME:2015-5-8
 * FROM:leetcode
 */
#include <iostream>
#include <algorithm>
using namespace std;

/* 素数发现算法，很牛，请参考(Primes)Sieve of Eratosthenes - Wikipedia, the free encyclopedia.mht文档
 * How many primes are there.mht文档
 * 里面详细讨论了小于等于n的所有素数的快速求法（本题不要求求等于n的素数）
 */
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		bool *a = new bool[n];

		if (n <= 1)
			return count;
		for (int i = 0; i < n; i++)
			a[i] = true;
		for (int i = 2; i <= sqrt(n); i++){
			if (a[i]){
				for (int j = i*i; j < n; j += i)
					a[j] = false;
			}
		}
		for (int i = 2; i < n; i++){
			if (a[i])
				count++;
		}

		delete[] a;
		return count;
	}
};

/* 这种算法时间复杂度太大 */
class Solution_1 {
public:
	int countPrimes(int n) {
		int count = 0;
		if (n <= 1)
			return count;
		for (int i = 2; i < n; i++){
			if (IsPrime(i))
				count++;
		}
		return count;
	}
private:
	bool IsPrime(int n)
	{
		int i = 2;
		int sqrtRoot = (int)sqrt(n);
		if (n <= 1)
			return false;
		while (i <= sqrtRoot && n % i)
			i++;
		if (i > sqrtRoot)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	//cout << s.IsPrime(93) << endl;
	cout << s.countPrimes(13);
	system("pause");
}