/*@TITLE:Populating Next Right Pointers in Each Node
 *		Given a binary tree
		struct TreeLinkNode {
		  TreeLinkNode *left;
		  TreeLinkNode *right;
		  TreeLinkNode *next;
		}
		Populate each next pointer to point to its next right node. 
		If there is no next right node, the next pointer should be set to NULL.
		Initially, all next pointers are set to NULL.
		Note:
		You may only use constant extra space.
		You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
		For example,
		Given the following perfect binary tree,
				 1
			   /  \
			  2    3
			 / \  / \
			4  5  6  7
		After calling your function, the tree should look like:
				 1 -> NULL
			   /  \
			  2 -> 3 -> NULL
			 / \  / \
			4->5->6->7 -> NULL
 *
 *@TIME:2015-6-16
 *@TYPE:Tree/DFS
 *@FROM:leetcode
 *@AUTHOR:PengSc
 */
#include <iostream>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/* 初一看需要用BFS，但实际上没必要
 * DFS代码更为简洁
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;
		TreeLinkNode *leftSub = root->left; //左子节点
		TreeLinkNode *rightSub = root->right; //右子节点
		if (leftSub){
			leftSub->next = rightSub;
		}
		if (rightSub && root->next){ //root->next在本次调用的父调用中已经处理过了
			rightSub->next = root->next->left; //这是重点
		}
		connect(leftSub);
		connect(rightSub);
	}
};

int main()
{
	Solution sl;  //测试，参考leetcode
}