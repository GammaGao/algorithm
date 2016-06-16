/* @TITLE: Invert Binary Tree(反转二叉树，即二叉树镜像)
 *		Invert a binary tree.
			 4
		   /   \
		  2     7
		 / \   / \
		1   3 6   9
 *		to
			 4
		   /   \
		  7     2
		 / \   / \
		9   6 3   1
 *
 * @TIME:2015-6-14
 * @TYPE:Tree
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"

/* 思路：自根节点向下，依次把左右子树交换，即可。
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		swap(root->left, root->right); //交换左右子树
		invertTree(root->left);  //处理现在的左子树
		invertTree(root->right); //处理现在的右子树
		return root;
	}
};

int main()
{
	Solution sl;
	TreeNode *res;
	//		1
	//	   / \
	//    2   3
	//   /   / \
	//  4   5   6
	TreeNode *p1 = CreateBinaryTreeNode(1);
	TreeNode *p2 = CreateBinaryTreeNode(2);
	TreeNode *p3 = CreateBinaryTreeNode(3);
	TreeNode *p4 = CreateBinaryTreeNode(4);
	TreeNode *p5 = CreateBinaryTreeNode(5);
	TreeNode *p6 = CreateBinaryTreeNode(6);
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, NULL);
	ConnectTreeNodes(p3, p5, p6);
	res = sl.invertTree(p1);
	PrintTree(p1);
	DestroyTree(p1);
	system("pause");
}