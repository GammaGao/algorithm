/* @TITLE:Binary Search Tree Iterator(实现一颗二叉树的游标)
 *		Implement an iterator over a binary search tree (BST).
 *		Your iterator will be initialized with the root node of a BST.
 *		Calling next() will return the next smallest number in the BST. 
 *		Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 *		where h is the height of the tree.
 *
 * @TIME:2015-6-14
 * @TYPE:Tree
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include <stack>
#include "BinaryTree.h"

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/* 性能：时间hasNext()和next()方法的时间复杂度确实做到了O(1), 但整个程序的空间复杂度为O(n)，
 *		其中n为节点个数，但是题目要求用的空间复杂大为O(h)，h为BST树高。
 */
class BSTIterator_1 {
public:
	BSTIterator_1(TreeNode *root) {
		index = 0;
		inorderTraval(root); //中序列遍历
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (index < iter.size())
			return true;
		return false;
	}

	/** @return the next smallest number */
	int next() {
		return iter[index++];
	}
private:
	std::vector<int> iter;
	int index; //遍历iter的索引值

private:
	// 中序遍历，将所有节点存放在vector<int>容器中
	void inorderTraval(TreeNode *root){
		if (root){
			inorderTraval(root->left);
			iter.push_back(root->val);
			inorderTraval(root->right);
		}
	}
};

/* 思路，其实必须把所有节点都存放在容器里，只放一部分，需要时再进行查找
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findNext(root); //把树的左子树节点放入栈中
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *curr = s.top();
		s.pop(); //出栈
		findNext(curr->right); //遍历右子树
		return curr->val;
	}
private:
	stack<TreeNode *> s; //使用栈来存放部分节点，size()小于树高h

private:
	void findNext(TreeNode *root){
		while (root){
			s.push(root);
			root = root->left;
		}
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

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
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, p7);
	ConnectTreeNodes(p3, p5, p6);

	BSTIterator i = BSTIterator(p1);
	while (i.hasNext()){
		cout << i.next() << endl;
	}
	DestroyTree(p1);
	system("pause");
}