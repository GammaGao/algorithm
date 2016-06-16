#include <iostream>
/* @TITLE: Binary Tree Preorder Traversal(二叉树的先序遍历)
 *		Given a binary tree, return the preorder traversal of its nodes' values.
 *		For example:
 *		Given binary tree {1,#,2,3},
		   1
			\
			 2
			/
		   3
 *		return [1,2,3].
 *
 * @TIME:2015-6-14
 * @TYPE:Binary Tree
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <vector>
#include "BinaryTree.h"

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderTraversal(res, root);
		return res;
	}
private:
	void preorderTraversal(vector<int> &res, TreeNode *root){
		if (root){
			res.push_back(root->val);
			preorderTraversal(res, root->left); //左子树
			preorderTraversal(res, root->right);//右子树
		}
	}
};

int main()
{
	//		4
	//	   / \
	//    2   7
	//   /\   /\
	//  1  3 6  8
	TreeNode *p1 = CreateBinaryTreeNode(4);
	TreeNode *p2 = CreateBinaryTreeNode(2);
	TreeNode *p3 = CreateBinaryTreeNode(7);
	TreeNode *p4 = CreateBinaryTreeNode(1);
	TreeNode *p5 = CreateBinaryTreeNode(6);
	TreeNode *p6 = CreateBinaryTreeNode(8);
	TreeNode *p7 = CreateBinaryTreeNode(3);
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, p7);
	ConnectTreeNodes(p3, p5, p6);

	Solution sl;
	vector<int> res = sl.preorderTraversal(p1);
	for (int i = 0; i < res.size(); i++){
		std::cout << res[i] << std::endl;
	}
	DestroyTree(p1);
	system("pause");
}