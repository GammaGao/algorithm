/* ��Ŀ������һ���˿��ƣ����һ��������ϴ���㷨��Ҫ���⸱��54�������У�ÿ��������ֵĸ�����ͬ��
 *		������һ���������������������
 * TIME��2015-5-5
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Solution{
public:
	/* �ٶ������������������, �ȸ��ʲ���low~high֮��������� */
	int PerfectRand(int low, int high)
	{
		return rand() % (high - low + 1) + low;
	}

	/* ���������г�54!�������У�����ȸ��ʵ�ѡ������һ�֣���Ȼ��������ʱ�临�Ӷ���O(n!)
	 *		�ռ临�Ӷ�O(n!*k)(kΪ�Ƶ�����)��
	 */
	/* �ݹ�˼·��54���ƣ���54!�����У�������Ҫ����ȸ��ʵĲ���54!�������е�һ�֡�
	 *		����ǰ���53�����Ѿ��ź�����ô��54���Ʊ��������ȸ��ʷ�����54��λ���е�һ����
	 *		�ݹ�����������̣���ϴ���ơ�
	 * ���ܣ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�����ΪO(1)��
	 */
	void RecursiveShuffle(vector<int> &board, int i)
	{
		if (i == 0)
			return;
		RecursiveShuffle(board, i-1);
		swap(board[i], board[PerfectRand(0, i)]); //��i���ƿ�������ȸ��ʵ����0~i���ƽ���������Ϊ1/(i+1)��
	}

	/* �ѵݹ鷨ת���ɵ���ʵ��
	 * ���ܣ�ʱ�临�Ӷ�O(n), ����ռ临�Ӷ�O��1��
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

	cout << "ϴ����֮���˳��" << endl;
	for (int i = 0; i < board.size(); i++)
		cout << board.at(i) << " ";
	cout << endl;
	system("pause");
}