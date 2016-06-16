/* @TITLE: Maximum Depth of Binary Tree
 *		Given a binary tree, find its maximum depth.
 *		The maximum depth is the number of nodes along 
 *		the longest path from the root node down to the farthest leaf node.
 *
 * @TIME:2015-5-28
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftHeight = maxDepth(root->left);
		int rightHeight = maxDepth(root->right);
		if (leftHeight == 0 && rightHeight == 0)
			return 1;
		else if (leftHeight == 0)
			return rightHeight + 1;
		else if (rightHeight == 0)
			return leftHeight + 1;
		else
			return (leftHeight >= rightHeight ? leftHeight : rightHeight) + 1;
	}
};

void test(void(*f)(), char *str)
{
	cout << str << endl;
	f();
}

//		1
//	   / \
//    2   3
//   / \
//  4   5
// return 2
void test01()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, p5);
	cout << sl.maxDepth(p1) << endl;
	DestroyTree(p1);
}

//		1
//	   /
//    2   
//   / \
//  4   5
// return 3
void test02()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);
	//BinaryTreeNode *p3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(p1, p2, NULL);
	ConnectTreeNodes(p2, p4, p5);
	cout << sl.maxDepth(p1) << endl;
	DestroyTree(p1);
}

//  1
// return 1
void test03()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	ConnectTreeNodes(p1, NULL, NULL);
	cout << sl.maxDepth(p1) << endl;
	DestroyTree(p1);
}

int main()
{
	test(test01, "²âÊÔÓÃÀý1");
	test(test02, "²âÊÔÓÃÀý2");
	test(test03, "²âÊÔÓÃÀý3");
	system("pause");
}