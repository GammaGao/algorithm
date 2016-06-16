/* @TITLE: Convert Sorted Array to Binary Search Tree
 *		Given an array where elements are sorted in ascending order,
 *		convert it to a height balanced BST.
 *
 * @TIME:2015-6-1
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

/* 转换结果不唯一
 */
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		return sortedArrayToBST(nums, 0, nums.size()-1);
	}
	TreeNode *sortedArrayToBST(vector<int>& nums, int start, int end)
	{
		if (start > end)
			return NULL;
		if (start == end)
			return new TreeNode(nums.at(start));
		int mid = (start + end) / 2;
		TreeNode *left_subtree = sortedArrayToBST(nums, start, mid - 1);
		TreeNode *right_subtree = sortedArrayToBST(nums, mid+1, end);
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = left_subtree;
		root->right = right_subtree;
	}
};

int main()
{
	Solution sl;
	vector<int> nums = { 1, 2, 3, 4, 5};
	TreeNode *res = sl.sortedArrayToBST(nums);
	PrintTree(res);
	DestroyTree(res);
	system("pause");
	return 0;
}