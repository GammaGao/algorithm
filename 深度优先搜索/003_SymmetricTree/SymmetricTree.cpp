/* @TITLE: Symmetric Tree
 *		Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *		For example, this binary tree is symmetric:
			1
		   / \
		  2   2
		 / \ / \
		3  4 4  3
 *		But the following is not:
			1
		   / \
		  2   2
		   \   \
		   3    3
 *
 * @TIME:2015-5-28	
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
private:
	bool isSymmetric(TreeNode* root1, TreeNode *root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		else if (root1 == NULL || root2 == NULL)
			return false;
		if (root1->val == root2->val)
			return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
		return false;
	}
};

void test(void(*f)(), char *str)
{
	cout << str << endl;
	f();
}

//		 1
//	   /   \
//    2     2
//   / \   / \
//  4   5 5   4
// return 2
void test01()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p2_1 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p4_1 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p5 = CreateBinaryTreeNode(5);
	BinaryTreeNode *p5_1 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(p1, p2, p2_1);
	ConnectTreeNodes(p2, p4, p5);
	ConnectTreeNodes(p2_1, p5_1, p4_1);
	cout << sl.isSymmetric(p1) << endl;
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
	cout << sl.isSymmetric(p1) << endl;
	DestroyTree(p1);
}

//     1
//	  / \
//   2   2
//    \   \
//     3   3
void test03()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p2_1 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *p3_1 = CreateBinaryTreeNode(3);

	ConnectTreeNodes(p1, p2, p2_1);
	ConnectTreeNodes(p2, NULL, p3);
	ConnectTreeNodes(p2_1, p3_1, NULL );
	cout << sl.isSymmetric(p1) << endl;
	DestroyTree(p1);
}

int main()
{
	test(test01, "²âÊÔÓÃÀý1");
	test(test02, "²âÊÔÓÃÀý2");
	test(test03, "²âÊÔÓÃÀý3");
	system("pause");
}