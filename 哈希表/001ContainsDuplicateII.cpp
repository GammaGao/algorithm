/* @TITLE: Contains Duplicate II
 *		Given an array of integers and an integer k, find out whether
 *		there there are two distinct indices i and j in the array such
 *		that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 * @TIME:2015-6-18
 * @TYPE:hash
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <hash_map>
#include <map>
#include <vector>
using namespace std;

/* 使用哈希表，时间复杂度为线性O(n), STL容器中选用hash_map或map,但leetcode上不支持hash_map容器
 * map是排序的，关联的，唯一键值对的容器，底层使用红黑树实现
 * hash_map是无序的，关联的，唯一键值对容器，底层用散列表实现
 * 也可以使用unordered_map() C++11
 */
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//hash_map<int, int> hm;
		map<int, int> hm;
		for (int i = 0; i < nums.size(); i++){
			//容器查找方法有两种，count()和find()方法，后者需要使用迭代器
			if (hm.count(nums[i]) == 1 && i - hm[nums[i]] <= k)
				return true;
			//插入键值对<nums[i], i>， 如果之前有nums[i]，但是不满足i - hm[nums[i]] <= k， 那么此时它会被更新
			hm[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	Solution sl;
	vector<int> nums = { 1, 2, 4, 3, 6, 2, 2, 20 };
	cout << sl.containsNearbyDuplicate(nums, 3);
	system("pause");
}