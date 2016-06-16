/* @TITLE: Path Sum II
 *		Given a binary tree and a sum, find all root-to-leaf paths
 *		 where each path's sum equals the given sum.
 *		For example:
 *		Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 *		return
		[
		   [5,4,11,2],
		   [5,8,4,5]
		]
 *
 * @TIME:2015-6-7
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		__pathSum(root, res, path, 0, sum);
		return res;
	}
private:
	void __pathSum(TreeNode *root, vector<vector<int>> &res, vector<int> &path, int currentSum, int sum)
	{
		if (!root)
			return;
		currentSum += root->val;
		path.push_back(root->val);
		if (root->left == NULL && root->right == NULL && currentSum == sum){ //满足要求的叶子节点
			res.push_back(path);
			path.pop_back();
			return;
		}
		__pathSum(root->left, res, path, currentSum, sum); //左子树
		__pathSum(root->right, res, path, currentSum, sum);//右子树
		path.pop_back();
	}
};

int main()
{
	Solution sl;
	vector<vector<int>> res;
	vector<int> path;
	//		 5
	//		/ \
	//	   4   8
	//	  /   / \
	//  11  13   4
	// / \	    / \
	//7   2    5   1
	TreeNode *p1_5 = CreateBinaryTreeNode(5);
	TreeNode *p2_4 = CreateBinaryTreeNode(4);
	TreeNode *p3_8 = CreateBinaryTreeNode(8);
	TreeNode *p4_11 = CreateBinaryTreeNode(11);
	TreeNode *p5_13 = CreateBinaryTreeNode(13);
	TreeNode *p6_4 = CreateBinaryTreeNode(4);
	TreeNode *p7_7 = CreateBinaryTreeNode(7);
	TreeNode *p8_2 = CreateBinaryTreeNode(2);
	TreeNode *p9_5 = CreateBinaryTreeNode(5);
	TreeNode *p10_1 = CreateBinaryTreeNode(1);
	ConnectTreeNodes(p1_5, p2_4, p3_8);
	ConnectTreeNodes(p2_4, p4_11, NULL);
	ConnectTreeNodes(p3_8, p5_13, p6_4);
	ConnectTreeNodes(p4_11, p7_7, p8_2);
	ConnectTreeNodes(p6_4, p9_5, p10_1);

	res = sl.pathSum(p1_5, 22);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	DestroyTree(p1_5);
	system("pause");
}