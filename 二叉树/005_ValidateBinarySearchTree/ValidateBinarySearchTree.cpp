/*@TITLE:Validate Binary Search Tree(判读是否是有效二叉树搜索树)
 *		Given a binary tree, determine if it is a valid binary search tree (BST).
 *		Assume a BST is defined as follows:
 *		The left subtree of a node contains only nodes with keys less than the node's key.
 *		The right subtree of a node contains only nodes with keys greater than the node's key.
 *		Both the left and right subtrees must also be binary search trees.
 *
 *@TIME:2015-6-16
 *@TYPE:BST
 *@FROM:leetcode
 *@AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		int res = false;
		if (root == NULL)
			return true;
		if (root->left && root->right){ //左右子树都存在
			TreeNode *left_most = leftMost(root->right); //右子树最左边的元素
			TreeNode *right_most = rightMost(root->left); //左子树最右边的元素
			if (root->left->val < root->val && root->right->val > root->val
				&& left_most->val > root->val && right_most->val < root->val)
				return isValidBST(root->left) && isValidBST(root->right);
			else
				return false;
		}
		else if (root->left){ //左子树存在
			TreeNode *right_most = rightMost(root->left);
			if (root->left->val < root->val && right_most->val < root->val)
				return isValidBST(root->left);
			else
				return false;
		}
		else if (root->right){ //右子树存在
			TreeNode *left_most = leftMost(root->right);
			if (root->right->val > root->val && left_most->val > root->val)
				return isValidBST(root->right);
			return false;
		}
		else
			return true;
	}
private:
	TreeNode* leftMost(TreeNode *root){
		while (root && root->left){
			root = root->left;
		}
		return root;
	}
	TreeNode* rightMost(TreeNode *root){
		while (root && root->right){
			root = root->right;
		}
		return root;
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
	cout << sl.isValidBST(p1) << endl;
	DestroyTree(p1);
	system("pause");
}