/* @TITLE: Contains Duplicate(�ظ�Ԫ��)
 *		Given an array of integers, find if the array contains
 *		any duplicates. Your function should return true if any
 *		value appears at least twice in the array, and it should
 *		return false if every element is distinct.
 * @TIME:2015-6-18
 * @TYPE:hash
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/* ʹ�ù�ϣ������C++ STL��unordered_set����
 * unordered_set�����ǹ����ģ�����ģ�ֻ����Ψһֵ���������ײ���ɢ�б�ʵ��
 * ��ȻҲ������set������set�����ǹ����ģ�����ģ�ֻ����Ψһ���������ײ��ú����ʵ��
 */
class Solution_1 {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> set;
		for (int i = 0; i < nums.size(); i++){
			if (set.count(nums[i]) != 0)
				return true;
			set.insert(nums[i]);
		}
		return false;
	}
};

/* ��Ȼʹ��unordered_set�������������ż��
 * �����ظ�Ԫ�صģ�unordered_set�����Ĵ�С�϶�Ҫ��nums.size()ҪС����Ϊ��ȥ���ظ�Ԫ��
 */
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size(); //��ʱ����, ������
		//return set<int>(nums.begin(), nums.end()).size() < nums.size(); //��set����
	}
};

/* ��Ȼ��ţ�Ļ����Լ�ʵ��hash���������ͻ����C���ԵĻ���ֻ���Լ�ʵ��hash����
 */
class Solution_3 {
public:
	bool containsDuplicate(vector<int>& nums) {
		/* ������C����*/
		struct Node
		{
			int val;
			struct Node *next;
		};

		struct Set
		{
			int bucketSize;
			struct Node **table;
		};

		void initSet(struct Set *set, int bucketSize)
		{
			set->bucketSize = bucketSize;
			set->table = malloc(sizeof(struct Node*) * bucketSize);
			memset(set->table, 0, sizeof(struct Node*) * bucketSize);
		}

		bool addValue(struct Set *s, int val)
		{
			int idx = val > 0 ? val : -val;
			idx %= s->bucketSize;
			struct Node *ptr = s->table[idx];
			while (ptr != NULL)
			{
				if (ptr->val == val)
				{
					return false;
				}

				ptr = ptr->next;
			}
			ptr = malloc(sizeof(struct Node));
			ptr->val = val;
			ptr->next = s->table[idx];
			s->table[idx] = ptr;
			return true;
		}
		void releaseSet(struct Set *s)
		{
			struct Node *ptr, *tmp;
			for (int i = 0; i < s->bucketSize; ++i)
			{
				ptr = s->table[i];
				while (ptr != NULL)
				{
					tmp = ptr;
					ptr = ptr->next;
					free(tmp);
				}
			}
			free(s->table);
			s->table = NULL;
			s->bucketSize = 0;
		}
		bool containsDuplicate(int* nums, int numsSize) {
			if (numsSize < 2)
			{
				return false;
			}
			struct Set set;
			initSet(&set, numsSize / 2);
			for (int i = 0; i < numsSize; ++i)
			{
				if (!addValue(&set, nums[i]))
				{
					releaseSet(&set);
					return true;
				}
			}
			releaseSet(&set);
			return false;
		}
	}
};

int main()
{
	//vector<int> nums = { 1, 2, 3, 84, 100, 2 };
	//vector<int> nums = { 0};
	vector<int> nums = { 3,1 };
	Solution sl;
	cout << sl.containsDuplicate(nums) << endl;
	system("pause");
}