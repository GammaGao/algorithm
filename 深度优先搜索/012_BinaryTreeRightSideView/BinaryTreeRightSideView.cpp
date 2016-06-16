/* @TITLE: Binary Tree Right Side View
 *		Given a binary tree, imagine yourself standing on the right side of it, 
 *		return the values of the nodes you can see ordered from top to bottom.
 *
 *		For example:
 *		Given the following binary tree,
		   1            <---
		 /   \
		2     3         <---
		 \     \
		  5     4       <---
 *		You should return [1, 3, 4].
 *
 * @TIME:2015-6-7
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

/* DFS：由于我们是站在右边，采用后序遍历，设置容器res，里面的元素个数代表我们遍历过的树的高度。
 *		depth代表将要遍历的树的高度，只有当depth大于它时，才是我们看到的
 */
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		rightSideView(root, res, 1);
		return res;
	}
private:
	void rightSideView(TreeNode *root, vector<int> &res, int depth)
	{
		if (!root)
			return;
		if (depth > res.size()){
			res.push_back(root->val);
		}
		rightSideView(root->right, res, depth+1);
		rightSideView(root->left, res, depth+1);
	}
};

int main()
{
	Solution sl;
	vector<int> res;

	 //   1
	 //  / \
	 // 2   3
	 //  \   \
	 //   5   4
	 //  /
	 // 6
	TreeNode *p1 = CreateBinaryTreeNode(1);
	TreeNode *p2 = CreateBinaryTreeNode(2);
	TreeNode *p3 = CreateBinaryTreeNode(3);
	TreeNode *p4 = CreateBinaryTreeNode(4);
	TreeNode *p5 = CreateBinaryTreeNode(5);
	TreeNode *p6 = CreateBinaryTreeNode(6);
	TreeNode *p8 = CreateBinaryTreeNode(8);

	ConnectTreeNodes(p1, p2, NULL);
	ConnectTreeNodes(p2, NULL, p5);
	//ConnectTreeNodes(p3, NULL, p4);
	ConnectTreeNodes(p5, p6, NULL);

	res = sl.rightSideView(p1);
	for (int i = 0; i < res.size(); i++)
		cout << res.at(i) << " ";
	cout << endl;
	DestroyTree(p1);
	system("pause");
}