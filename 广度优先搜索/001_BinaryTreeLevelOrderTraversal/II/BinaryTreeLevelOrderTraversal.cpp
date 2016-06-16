#include <iostream>
/* @TITLE: Binary Tree Level Order Traversal
 *		Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *		For example:
 *		Given binary tree {3,9,20,#,#,15,7},
			3
		   / \
		  9  20
			/  \
		   15   7
 *		return its level order traversal as:
		[
		  [3],
		  [9,20],
		  [15,7]
		]
 * @TIME:2015-6-7
 * @TYPE:BFS(�����������)
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <queue>
#include <vector>
#include "BinaryTree.h"
using namespace std;

/* BFS:���Ĳ����������������ڶ��в�ʵ�ֹ������
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		levelOrder(root, res);
		return res;
	}

private:
	void levelOrder(TreeNode *root, vector<vector<int>> &res)
	{
		queue<TreeNode*> q; //����
		TreeNode *curr; //��ǰ���ʵĽڵ�
		vector<int> level; //��ʱ����һ��Ľڵ�
		int now = 0, next = 0; //��ǰ��Ľڵ�������һ��Ľڵ���
		if (root == NULL)
			return;
		q.push(root);
		now = 1;
		while (!q.empty()){
			curr = q.front(); //���ʵ�ǰ�ڵ�
			q.pop(); //������
			now--; //��ǰ��ʣ��δ���ʽڵ���
			level.push_back(curr->val);

			if (curr->left){
				next++;
				q.push(curr->left);
			}
			if (curr->right){
				next++;
				q.push(curr->right);
			}

			if (now == 0){ //��ǰһ��������
				now = next;
				next = 0;
				res.push_back(level);
				level.clear();
			}
		}
	}
};

int main()
{
	Solution sl;
	vector<vector<int>> res;
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

	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, NULL, p5);
	ConnectTreeNodes(p3, NULL, p4);
	ConnectTreeNodes(p5, p6, NULL);
	res = sl.levelOrder(p1);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res.at(i).size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	DestroyTree(p1);
	system("pause");
}