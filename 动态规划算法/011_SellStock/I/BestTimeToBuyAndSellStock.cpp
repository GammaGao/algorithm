/* TITLE: Best Time To Buy And Sell Stock
 *		Say you have an array for which the ith element is the price of a given stock on day i.
 *		If you were only permitted to complete at most one transaction (ie, buy one and sell o-
 *		ne share of the stock), design an algorithm to find the maximum profit.
 *
 * TIME:2015-5-13
 * FROM:leetcode
 * TYPE:DP
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* �е�������������������������⣬��Ȼ������Ŀ����ת��
 * �����������ֵ����Ϳ��Եã����������������������һ���ġ�
 * ��Ȼ����ô���Ļ��ռ临�Ӷ�ΪO(n)
 * ��������������ö�̬�滮�㷨������ת��������������������⡣
 */
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int global_max = 0; //�����������
		int local_max = 0;
		int minStock = prices[0];
		for (int i = 1; i < prices.size(); i++){
			if (prices[i] < minStock) //��˵����ֵ�϶��ڵ�
				minStock = prices[i];
			else{
				local_max = prices[i] - minStock; //����ڹ�ֵ��͵�һ����˵����ֵ����
				if (local_max > global_max) //�жϽ���������ܷ�����
					global_max = local_max;
			}
		}
		return global_max;
	}
};

int main()
{
	Solution s;
	vector<int> prices = {10, 9, 8, 11, 18, 21, 19, 17, 16}; //21-8=13
	vector<int> prices1 = { 10, 9, 8, 7, 6, 6, 5}; //��Ʊÿ���
	vector<int> prices2 = {1, 2, 3, 4, 5, 6, 7, 8}; //��Ʊÿ����8-1=7
	vector<int> prices3 = {10, 10, 8, 7, 2, 3, 5, 15}; //�ȵ�����
	vector<int> prices4; //0
	vector<int> prices5 = {3}; //0
	vector<int> prices6 = { 3, 4}; //1
	cout << s.maxProfit(prices) << endl;
	cout << s.maxProfit(prices1) << endl;
	cout << s.maxProfit(prices2) << endl;
	cout << s.maxProfit(prices3) << endl;
	cout << s.maxProfit(prices4) << endl;
	cout << s.maxProfit(prices5) << endl;
	cout << s.maxProfit(prices6) << endl;
	system("pause");
}