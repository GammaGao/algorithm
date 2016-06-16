/* 机器人运动范围 */
#include <iostream>
using namespace std;

int moveCountCore(int, int, int, int, int, bool*);
bool check(int, int, int, int, int, bool*);
int getDigit(int);
int moveCount(int k, int m, int n)
{
	int count = 0;
	bool *visited = new bool[m*n];
	for (int i = 0; i < m*n; i++)
		visited[i] = false;
	if (k <= 0 || m <= 0 || n <= 0){
		return count;
	}
	count = moveCountCore(k, m, n, 0, 0, visited);
	delete[] visited;
	return count;
}

/*  */
int moveCountCore(int k, int m, int n, int i, int j, bool* visited)
{
	int count = 0;
	if (i < 0 || i >= m || j < 0 || j >= n || !check(k, m, n, i, j, visited)){
		return count;
	}

	visited[i*n + j] = true; //标记节点被访问
	cout << i << "," << j << endl;
	count = 1 + moveCountCore(k, m, n, i, j + 1, visited) + //往右走
		moveCountCore(k, m, n, i, j - 1, visited) + //往左走
		moveCountCore(k, m, n, i + 1, j, visited) + //往上走
		moveCountCore(k, m, n, i - 1, j, visited);	//往下走
	return count;
}

/* 访问格子的合法性检查 */
bool check(int k, int m, int n, int i, int j, bool* visited)
{
	if (i >= 0 && i < m && j >= 0 && j < n &&
		!visited[i*n + j] && getDigit(i)+getDigit(j) <= k){
		return true;
	}
	return false;
}

/* 数位之和 */
int getDigit(int number)
{
	int res = 0;
	while (number){
		res += number % 10;
		number /= 10;
	}
	return res;
}

int main()
{
	cout << moveCount(5, 3, 10) << endl;
}