/* 题目：给定一副扑克牌，设计一个完美的洗牌算法，要求这副牌54！种排列，每种情况出现的概率相同；
 *		假设有一个完美的随机数发生器。
 * TIME：2015-5-5
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Solution{
public:
	/* 假定的完美随机数发生器, 等概率产生low~high之间的任意数 */
	int PerfectRand(int low, int high)
	{
		return rand() % (high - low + 1) + low;
	}

	/* 蛮力法：列出54!各种排列，随机等概率的选择其中一种，显然这种做法时间复杂度是O(n!)
	 *		空间复杂度O(n!*k)(k为牌的张数)。
	 */
	/* 递归思路：54张牌，有54!种排列，我们需要随机等概率的产生54!种排列中的一种。
	 *		假如前面的53张牌已经排好序，那么第54张牌便可以随机等概率放入这54各位置中的一个。
	 *		递归完成上述过程，就洗完牌。
	 * 性能：时间复杂度O(n)，空间复杂度至少为O(1)。
	 */
	void RecursiveShuffle(vector<int> &board, int i)
	{
		if (i == 0)
			return;
		RecursiveShuffle(board, i-1);
		swap(board[i], board[PerfectRand(0, i)]); //第i张牌可以随机等概率地与第0~i张牌交换（概率为1/(i+1)）
	}

	/* 把递归法转换成迭代实现
	 * 性能：时间复杂度O(n), 额外空间复杂度O（1）
	 */
	void Shuffle(vector<int> &board)
	{
		for (int i = 1; i < board.size(); i++)
			swap(board[i], board[PerfectRand(0, i)]);
	}
};

int main()
{
	Solution s;
	vector<int> board;
	srand(time(0));

	for (int i = 1; i <= 54; i++)
		board.push_back(i);
	//s.RecursiveShuffle(board, 53);
	s.Shuffle(board);

	cout << "洗完牌之后的顺序：" << endl;
	for (int i = 0; i < board.size(); i++)
		cout << board.at(i) << " ";
	cout << endl;
	system("pause");
}