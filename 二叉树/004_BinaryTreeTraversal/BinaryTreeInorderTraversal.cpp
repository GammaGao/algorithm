/* @TITLE:Binary Tree Inorder Traversal(���������������)
 *		Given a binary tree, return the inorder traversal of its nodes' values.
 *		For example:
 *		Given binary tree {1,#,2,3},
		   1
			\
			 2
			/
		   3
 *		return [1,3,2].
 * @TIME:2015-6-15
 * @TYPE:Binary Tree
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
#include "BinaryTree.h"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/* �ݹ�ʵ��
 */
class Solution_1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorderTraversal(root, res);
		return res;
	}
private:
	void inorderTraversal(TreeNode *root, vector<int> &res){
		if (root){
			inorderTraversal(root->left, res);
			res.push_back(root->val);
			inorderTraversal(root->right, res);
		}
	}
};

/* ��������Ч����Ȼ�ȵݹ�ʵ��Ҫ�ã�����������δ����ظ���ջ����
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		unordered_set<TreeNode *> set;
		if (root){
			stack<TreeNode*> s;
			s.push(root);
			while (!s.empty()){
				TreeNode *p = s.top();
				//ͨ��set.count()��ֵ�Ƿ�Ϊ0�ж��Ƿ��Ѿ��������ýڵ�
				while (p->left && set.count(p->left) == 0){ //����������ȴ���������
					s.push(p->left); 
					set.insert(p->left); //���뵽set�����У������TreeNode*,������p->val����ֵ֤��Ψһ��
					p = s.top();
				}
				res.push_back(p->val);
				s.pop(); //��ջ�������ظ�push_back����res
				if (p->right && set.count(p->right) == 0){ //����һ�����ӽڵ㣬���Ǵ���������
					s.push(p->right);
					set.insert(p->right);
					p = s.top();
				}
			}
		}
		return res;
	}
};

int main()
{
	//		4
	//	   / \
	//    2   7
	//   /\   /\
	//  1  3 6  8
	TreeNode *p1 = CreateBinaryTreeNode(4);
	TreeNode *p2 = CreateBinaryTreeNode(2);
	TreeNode *p3 = CreateBinaryTreeNode(7);
	TreeNode *p4 = CreateBinaryTreeNode(1);
	TreeNode *p5 = CreateBinaryTreeNode(6);
	TreeNode *p6 = CreateBinaryTreeNode(8);
	TreeNode *p7 = CreateBinaryTreeNode(3);
	ConnectTreeNodes(p1, NULL, p3);
	//ConnectTreeNodes(p2, p4, p7);
	ConnectTreeNodes(p3, p5, p6);

	Solution sl;
	vector<int> res = sl.inorderTraversal(p1);
	for (int i = 0; i < res.size(); i++){
		std::cout << res[i] << std::endl;
	}
	DestroyTree(p1);
	system("pause");
}