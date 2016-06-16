/* @TITLE: Contains Duplicate(重复元素)
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

/* 使用哈希表处理，用C++ STL中unordered_set容器
 * unordered_set容器是关联的，无序的，只包含唯一值的容器，底层用散列表实现
 * 当然也可以用set容器，set容器是关联的，有序的，只包含唯一的容器，底层用红黑树实现
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

/* 依然使用unordered_set容器，代码优雅简洁
 * 当用重复元素的，unordered_set容器的大小肯定要比nums.size()要小，因为会去掉重复元素
 */
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size(); //临时容器, 匿名的
		//return set<int>(nums.begin(), nums.end()).size() < nums.size(); //用set容器
	}
};

/* 当然够牛的话，自己实现hash表，并处理冲突，用C语言的话，只能自己实现hash表了
 */
class Solution_3 {
public:
	bool containsDuplicate(vector<int>& nums) {
		/* 以下是C语言*/
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