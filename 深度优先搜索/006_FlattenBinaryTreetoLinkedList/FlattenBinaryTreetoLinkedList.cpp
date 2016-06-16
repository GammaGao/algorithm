/* @TITLE: Flatten Binary Tree to Linked List 
 *		Given a binary tree, flatten it to a linked list in-place.
 *		For example,
 *		Given

				 1
				/ \
			   2   5
			  / \   \
			 3   4   6
 *		The flattened tree should look like:
		   1
			\
			 2
			  \
			   3
				\
				 4
				  \
				   5
					\
					 6
 *
 * @TIME:2015-5-30
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* 先序遍历DFS
 */
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		flatten(root->left);
		flatten(root->right);
		TreeNode *tmp_left = root->left, *tmp_right = root->right;
		if (root->left){
			root->right = tmp_left;
			root->left = NULL;
			TreeNode *tail = FindTailList(tmp_left);
			tail->right = tmp_right;
		}
	}
private:
	/* 查找链表尾节点 */
	TreeNode *FindTailList(TreeNode *root)
	{
		TreeNode *p = root;
		while (p && p->right)
			p = p->right;
		return p;
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

	sl.flatten(p1);
	PrintTree(p1);
	DestroyTree(p1);
}

int main()
{
	test(test01, "测试用例1");
	system("pause");
}