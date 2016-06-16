/* @TITLE: Sum Root to Leaf Numbers
 *		Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *		An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *		Find the total sum of all root-to-leaf numbers.
 *		For example,
			1
		   / \
		  2   3
 *		The root-to-leaf path 1->2 represents the number 12.
 *		The root-to-leaf path 1->3 represents the number 13.
 *		Return the sum = 12 + 13 = 25.
 *
 * @TIME:2015-5-30
 * @TYPE:DRS
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* DFS:只是注意只有左右子节点均为空时，才算一个数
 */
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return 0;
		int sum = 0, current_num = 0;
		sumNumbers(root, sum, current_num); 
		return sum;
	}
private:
	void sumNumbers(TreeNode *root, int &sum, int current_num)
	{
		if (root){
			if (root->left == NULL && root->right == NULL){
				sum += current_num * 10 + root->val;
				return;
			}
			current_num = current_num * 10 + root->val;
			sumNumbers(root->left, sum, current_num);
			sumNumbers(root->right, sum, current_num);
		}
	}
};

void test(void(*f)(), char *str)
{
	cout << str << endl;
	f();
}

//		1
//	   /
//    2 
//     \
//      5
void test01()
{
	Solution sl;
	BinaryTreeNode *p1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *p2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *p3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *p4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *p5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(p1, p2, NULL);
	ConnectTreeNodes(p2, NULL, p5);

	cout << sl.sumNumbers(p1) << endl;
	DestroyTree(p1);
}

int main()
{
	test(test01, "测试用例1");
	system("pause");
}