/* 题目：找出数组中两数之和为指定值的所有整数对。
 * TIME:2015-5-4
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 思路：除了使用hash表外，另一种算法，先对元素按增排序，从头和尾两端扫描元素
 * 性能：时间复杂度O(nlogn)+O(n), 空间复杂度为O(1)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int start, end;
		vector<int> res;
		/* std:sort() sorts elements in ascending order in default. */
		std::sort(nums.begin(), nums.end());
		start = 0;
		end = nums.size()-1;
		while(start < end){
			if(nums[start] + nums[end] == target){
				res.push_back(start+1); //下标从1开始
				res.push_back(end+1);
				start++;
				end--;
			}
			else if(nums[start] + nums[end] < target){
				start++;
			}
			else
				end--;
		}
		return res;
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
