/* @TITLE: Path Sum 
 *		Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 *		such that adding up all the values along the path equals the given sum.
 *		For example:
 *		Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 *		return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * @TIME:2015-5-28
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* root->leaf path sum
 */
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		int pathSum = 0;
		if (root == NULL)
			return false;
		return hasPathSum(root, sum, pathSum);
	}
private:
	bool hasPathSum(TreeNode* root, int sum, int pathSum)
	{
		bool res = false;
		if (root == NULL)
			return false;
		pathSum += root->val;
		if (pathSum == sum && root->left == NULL && root->right == NULL)
			return true;
		res = hasPathSum(root->left, sum, pathSum);
		if (!res)
			res = hasPathSum(root->right, sum, pathSum);
		return res;
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
	cout << sl.hasPathSum(p1, 8) << endl;
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
	cout << sl.hasPathSum(p1, 7) << endl;
	DestroyTree(p1);
}

//		1
//	   /
//    2
// return 3
void test03()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(p1, p2, NULL);
	cout << sl.hasPathSum(p1, 1) << endl;
	DestroyTree(p1);
}
int main()
{
	test(test01, "²âÊÔÓÃÀý1");
	test(test02, "²âÊÔÓÃÀý2");
	test(test03, "²âÊÔÓÃÀý3");
	system("pause");
}