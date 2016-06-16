/* @TITLE:��������������
 *		����һ�����У����䵥�����������У���{2,1,4,2,3,7,4,6}��LIS��{1,2,3,4,6}�� ����Ϊ5
 * @TIME:2015-6-27
 * @FROM:�㷨���ۼ���Ѷĳ�����
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ˼·1����������������У� ת��������������С��磬����2, 1, 4, 2, 3, 7, 4, 6�� ������������
 *		1��2��2��3��4��4��6��7�� ��ô�������������Ϊ1,2,3,4,6, ��Ϊ��Ĺ��������С�
 * ���ܣ�ʱ�临�Ӷ�O(n^2), �ռ临�Ӷ�O(n^2), ���������㷨��
 */
class Solution_1{
public:
		int LIS(vector<int> nums){
		if (nums.size() == 0)
			return 0;
		vector<int> numsB(nums);
		sort(numsB.begin(), numsB.end()); //O(nlogn)
		return LCS(nums, numsB);
	}

	/* �����������, ʱ�临�Ӷ�O(m*n)�� �ռ临�Ӷ�O(m*n) */
	int LCS(vector<int> numsA, vector<int> numsB){
		if (numsA.size() == 0 || numsB.size() == 0)
			return 0;

		int m = numsA.size();
		int n = numsB.size();
		vector<vector<int>> c;
		for (int i = 0; i <= m; i++){
			vector<int> tmp;
			for (int j = 0; j <= n; j++){
				tmp.push_back(0);
			}
			c.push_back(tmp);
			tmp.clear();
		}

		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (numsA[i-1] == numsB[j-1])
					c[i][j] = c[i - 1][j - 1] + 1;
				else if (c[i][j - 1] >= c[i - 1][j])
					c[i][j] = c[i][j - 1];
				else
					c[i][j] = c[i - 1][j];
			}
		}

		return c[m][n];
	}
};

/* ˼·2����̬�滮�㷨, ����һ������6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6, 8��9
 *		˳��ɨ�裬 ɨ�赽6ʱ��LISΪ6�� ����Ϊ1��ɨ�赽1ʱ�� LISȡ1������6(��Ϊ�����п��ܱ�6С����1��������ڣ�ѡ1�������˵���ŵ�ѡ��)
 *		ɨ�赽8ʱ��LISΪ1��8����Ϊ2��ɨ�赽3ʱ��LISѡ1��3(1��8���滻), ��Ϊ������ܴ���С��8��������3����������1��3�ɹ��ɸ����ĵ��������У�
 *		ɨ�赽10ʱ��LISΪ1,3,8,10...ɨ�赽13ʱ��LISΪ1,3,8,10,11,12,13����Ϊ7��ɨ�赽4ʱ�����ǿ����ö��ֲ����㷨�ѵ�һ��С��4������һλ�滻��
 *		��ô1,3,4,10,11,12,13�� ����7(ע���ʱ������LIS�� �ؼ�������Ϊ�滻�󳤶Ȳ��䣬 ���Ҽ������������ɸ�С��10������4������ʹ���ȴ���7)
 *		ͬ��ɨ�赽9ʱ�����б��1,3,4,5,6,7,8,9����Ϊ8�ȸղŵ�7���������LIS.
 * ����ϸ���ͣ�http://blog.csdn.net/zhangguixian5/article/details/8205631
 * ���ܣ�ʱ�临�Ӷ�O(nlogn), �ռ临�Ӷ�O(n)
 */
class Solution {
public:
	int LIS(vector<int> nums){
		if (nums.size() == 0)
			return 0;
		vector<int> increaseSeq;
		increaseSeq.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] > increaseSeq[increaseSeq.size() - 1]) //�����ǰԪ�ر�increaseSeq�����һ��Ԫ�ش���ô���ؽ��ж��ֲ���
				increaseSeq.push_back(nums[i]);	//ֱ����ӵ�������
			else{
				int j = binarySearch(increaseSeq, nums[i]);
				increaseSeq[j] = nums[i]; //�ҵ�λ���滻
			}
		}
		return increaseSeq.size();
	}

	/* ���ֲ����㷨�� ���Ҳ���Ԫ��ʱ��nums[i] < key < nums[j]�������ص�������j�� ����i�� ��һ�����Ҫ*/
	int binarySearch(vector<int> nums, int key){
		int start = 0, end = nums.size()-1;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] == key)
				return mid;
			if (nums[mid] < key)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return start;
	}
};

void test01()
{
	Solution sl;
	Solution_1 sl2;
	vector<int> nums = { 2, 1, 4, 2, 3, 7, 4, 6 };
	cout << sl.LIS(nums) << endl; //1, 2, 3, 4, 6, len = 5
	cout << sl2.LIS(nums) << endl;
	cout << "--------------------------------" << endl;
}

void test02()
{
	Solution sl;
	Solution_1 sl2;
	vector<int> nums = { 6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6};
	cout << sl.LIS(nums) << endl; //1, 3, 10, 11, 12, 13��6, 8, 10, 11, 12, 13
	cout << sl2.LIS(nums) << endl;
	cout << "--------------------------------" << endl;
}

void test03()
{
	Solution sl;
	Solution_1 sl2;
	vector<int> nums = { 6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6, 8 };
	cout << sl.LIS(nums) << endl; //1, 3, 4, 5, 6, 8��  6, 8, 10, 11, 12, 13 �� 1, 3, 10, 11, 12, 13, len = 6
	cout << sl2.LIS(nums) << endl;
	cout << "--------------------------------" << endl;
}

void test04()
{
	Solution sl;
	Solution_1 sl2;
	vector<int> nums = { 6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6, 8, 9};
	cout << sl.LIS(nums) << endl; //1, 3, 4, 5, 6, 8, 9, len = 7
	cout << sl2.LIS(nums) << endl;
	cout << "--------------------------------" << endl;
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	//vector<int> nums = { 2, 1, 4, 2, 3, 7, 4, 6, 8, 10, 5 };
	//
	
	//vector<int> nums = { 1, 3, 10, 11, 12, 13 };
	//cout << sl.binarySearch(nums, 4) << endl;
	system("pause");
}