/* @TITLE: Same Tree
 *		Given two binary trees, write a function to check if they are equal or not.
 *		Two binary trees are considered equal if they are structurally identical and
 *		the nodes have the same value.
 *
 * @TIME:2015-5-28
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* 两个树相等与两颗树对称不同，可能有部分书上把两个树对称也当做相等 
 */
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p == NULL || q == NULL)
			return false;
		else
			if (p->val == q->val)
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		return false;
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

	BinaryTreeNode *p1_1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2_1 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p3_1 = CreateBinaryTreeNode(3);
	BinaryTreeNode *p4_1 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p5_1 = CreateBinaryTreeNode(5);
	ConnectTreeNodes(p1_1, p2_1, p3_1);
	ConnectTreeNodes(p2_1, p4_1, p5_1);

	cout << sl.isSameTree(p1, p1_1) << endl;
	DestroyTree(p1);
	DestroyTree(p1_1);
}

int main()
{
	test(test01, "测试用例1");
	system("pause");
}