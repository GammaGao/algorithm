/* @TITLE:单调递增子序列
 *		给定一个序列，求其单调递增子序列，如{2,1,4,2,3,7,4,6}的LIS是{1,2,3,4,6}， 长度为5
 * @TIME:2015-6-27
 * @FROM:算法导论及腾讯某年笔试
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 思路1：最长公共递增子序列， 转换成最长公共子序列。如，序列2, 1, 4, 2, 3, 7, 4, 6， 对其递增排序后
 *		1，2，2，3，4，4，6，7， 那么其最长公共子序列为1,2,3,4,6, 即为最长的公共子序列。
 * 性能：时间复杂度O(n^2), 空间复杂度O(n^2), 均非最优算法。
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

	/* 最长公共子序列, 时间复杂度O(m*n)， 空间复杂度O(m*n) */
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

/* 思路2：动态规划算法, 给定一个序列6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6, 8，9
 *		顺序扫描， 扫描到6时，LIS为6， 长度为1；扫描到1时， LIS取1而不是6(因为后面有可能比6小，比1大的数存在，选1是相对来说较优的选择)
 *		扫描到8时，LIS为1，8长度为2；扫描到3时，LIS选1，3(1，8被替换), 因为后面可能存在小于8，但大于3的数，它与1，3可够成更长的递增子序列；
 *		扫描到10时，LIS为1,3,8,10...扫描到13时，LIS为1,3,8,10,11,12,13长度为7；扫描到4时，我们可以用二分查找算法把第一个小于4的数后一位替换掉
 *		那么1,3,4,10,11,12,13， 长度7(注意此时它不是LIS， 关键在于因为替换后长度不变， 而且假如后面存在若干个小于10但大于4的数，使长度大于7)
 *		同理扫描到9时，序列变成1,3,4,5,6,7,8,9长度为8比刚才的7大，这个才是LIS.
 * 更详细解释：http://blog.csdn.net/zhangguixian5/article/details/8205631
 * 性能：时间复杂度O(nlogn), 空间复杂度O(n)
 */
class Solution {
public:
	int LIS(vector<int> nums){
		if (nums.size() == 0)
			return 0;
		vector<int> increaseSeq;
		increaseSeq.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] > increaseSeq[increaseSeq.size() - 1]) //如果当前元素比increaseSeq中最后一个元素大，那么不必进行二分查找
				increaseSeq.push_back(nums[i]);	//直接添加到容器中
			else{
				int j = binarySearch(increaseSeq, nums[i]);
				increaseSeq[j] = nums[i]; //找到位置替换
			}
		}
		return increaseSeq.size();
	}

	/* 二分查找算法， 当找不到元素时（nums[i] < key < nums[j]），返回的索引是j， 而非i， 这一点很重要*/
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
	cout << sl.LIS(nums) << endl; //1, 3, 10, 11, 12, 13或6, 8, 10, 11, 12, 13
	cout << sl2.LIS(nums) << endl;
	cout << "--------------------------------" << endl;
}

void test03()
{
	Solution sl;
	Solution_1 sl2;
	vector<int> nums = { 6, 1, 8, 3, 10, 11, 12, 13, 4, 5, 6, 8 };
	cout << sl.LIS(nums) << endl; //1, 3, 4, 5, 6, 8或  6, 8, 10, 11, 12, 13 或 1, 3, 10, 11, 12, 13, len = 6
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