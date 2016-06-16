/* @TITLE: Minimum Depth of Binary Tree
 *		Given a binary tree, find its minimum depth.
 *		The minimum depth is the number of nodes along the shortest path from the 
 *		root node down to the nearest leaf node.
 *
 * @TIME:2015-5-26
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* 注意最小深度的定义，由根节点到叶子的最短路径长度 */
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftHeight = minDepth(root->left);
		int rightHeight = minDepth(root->right);

		if (leftHeight == 0 && rightHeight == 0)
			return 1;
		else if (leftHeight == 0)
			return rightHeight + 1;
		else if (rightHeight == 0)
			return leftHeight + 1;
		else if (leftHeight <= rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
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
	cout << sl.minDepth(p1) << endl;
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
	cout << sl.minDepth(p1) << endl;
	DestroyTree(p1);
}

int main()
{
	test(test01, "测试用例1");
	test(test02, "测试用例2");
	system("pause");
}