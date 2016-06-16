/* @TITLE:Binary Tree Zigzag Level Order Traversal(二叉树的Z字形遍历)
 *		Given a binary tree, return the zigzag level order traversal of its nodes' values.
 *		(ie, from left to right, then right to left for the next level and alternate between).
 *		For example:
 *		Given binary tree {3,9,20,#,#,15,7},
			3
		   / \
		  9  20
			/  \
		   15   7
 *		return its zigzag level order traversal as:
		[
		  [3],
		  [20,9],
		  [15,7]
		]
 * @TIME:2015-6-12
 * @TYPE:BFS/Stack
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "BinaryTree.h"
using namespace std;

/* 两叉树的Z字形遍历
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		vector<int>tmp;
		if (root == NULL)
			return res;
		TreeNode *curr = root;
		stack<TreeNode*> s; //只用一个栈处理起来比较麻烦，还得分奇偶
		stack<TreeNode*> q;
		q.push(root);
		while (!q.empty() || !s.empty()){
			while (!q.empty()){
				TreeNode *curr = q.top();
				if (curr->left)
					s.push(curr->left);
				if (curr->right)
					s.push(curr->right);
				tmp.push_back(curr->val);
				q.pop();
			}
			if (!tmp.empty()){
				res.push_back(tmp);
				tmp.clear();
			}
			while (!s.empty()){
				TreeNode *curr = s.top();
				if (curr->right)
					q.push(curr->right);
				if (curr->left)
					q.push(curr->left);
				tmp.push_back(curr->val);
				s.pop();
			}
			if (!tmp.empty()){
				res.push_back(tmp);
				tmp.clear();
			}
		}
		return res;
	}
};

int main()
{
	Solution sl;
	vector<vector<int>> res;
	TreeNode *p1 = CreateBinaryTreeNode(1);
	TreeNode *p2 = CreateBinaryTreeNode(2);
	TreeNode *p3 = CreateBinaryTreeNode(3);
	TreeNode *p4 = CreateBinaryTreeNode(4);
	TreeNode *p5 = CreateBinaryTreeNode(5);
	TreeNode *p6 = CreateBinaryTreeNode(6);
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, NULL);
	ConnectTreeNodes(p3, p5, p6);
	res = sl.zigzagLevelOrder(p1);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res.at(i).size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	DestroyTree(p1);
	system("pause");
}