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

/* ʹ�ù�ϣ��ʱ�临�Ӷ�Ϊ����O(n), STL������ѡ��hash_map��map,��leetcode�ϲ�֧��hash_map����
 * map������ģ������ģ�Ψһ��ֵ�Ե��������ײ�ʹ�ú����ʵ��
 * hash_map������ģ������ģ�Ψһ��ֵ���������ײ���ɢ�б�ʵ��
 * Ҳ����ʹ��unordered_map() C++11
 */
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//hash_map<int, int> hm;
		map<int, int> hm;
		for (int i = 0; i < nums.size(); i++){
			//�������ҷ��������֣�count()��find()������������Ҫʹ�õ�����
			if (hm.count(nums[i]) == 1 && i - hm[nums[i]] <= k)
				return true;
			//�����ֵ��<nums[i], i>�� ���֮ǰ��nums[i]�����ǲ�����i - hm[nums[i]] <= k�� ��ô��ʱ���ᱻ����
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