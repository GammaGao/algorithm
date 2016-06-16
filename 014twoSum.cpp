/* 题目：找出数组中两数之和为指定值的所有整数对。
 * TIME：2015-5-3
 * 测试：通过leetcode oj测试
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* 思路：先查找散列表，若存在x, 则直接查找sum-x；否则，将x加入散列表，继续处理下一个元素。
 * 性能：遍历一次，时间复杂度O(n)，空间复杂度O(n)。
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
		vector<int> res;
		map<int, int> hmap;
		for(i = 0; i < nums.size(); i++){
			/* std::map::count():Searches the container for the elements with key,
			 * and return the number of mathes. But we know all elements in the
			 * map is unique. So return 1 if found, otherwise 0.
			 */
			if(!hmap.count(nums[i]))//查找要插入的元素是否存在与map容器中
				hmap.insert(pair<int, int>(nums[i], i));
			if(hmap.count(target - nums[i])){//存在target-x=y
				int n = hmap[target - nums[i]];
				/* 由于边插入边扫描，故只会存在n < i或 n==i（指向同一个元素） */
				if(n < i){
					res.push_back(n+1); //返回的索引从1开始的
					res.push_back(i+1);
					return res;
				}
			}
		}
    }
};

int main()
{
	Solution s;
	int n, sum, x;
	vector<int> in, out;
	cin >> n >> sum;
	while(n--){
		cin >> x;
		in.push_back(x);
	}
	out = s.twoSum(in, sum);
	for(int i = 0; i < out.size(); i += 2)
		cout << out[i] << "," << out[i+1] << endl;
}