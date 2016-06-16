/* @TITLE:Binary Search Tree Iterator(ʵ��һ�Ŷ��������α�)
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

/* ���ܣ�ʱ��hasNext()��next()������ʱ�临�Ӷ�ȷʵ������O(1), ����������Ŀռ临�Ӷ�ΪO(n)��
 *		����nΪ�ڵ������������ĿҪ���õĿռ临�Ӵ�ΪO(h)��hΪBST���ߡ�
 */
class BSTIterator_1 {
public:
	BSTIterator_1(TreeNode *root) {
		index = 0;
		inorderTraval(root); //�����б���
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
	int index; //����iter������ֵ

private:
	// ��������������нڵ�����vector<int>������
	void inorderTraval(TreeNode *root){
		if (root){
			inorderTraval(root->left);
			iter.push_back(root->val);
			inorderTraval(root->right);
		}
	}
};

/* ˼·����ʵ��������нڵ㶼����������ֻ��һ���֣���Ҫʱ�ٽ��в���
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findNext(root); //�������������ڵ����ջ��
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *curr = s.top();
		s.pop(); //��ջ
		findNext(curr->right); //����������
		return curr->val;
	}
private:
	stack<TreeNode *> s; //ʹ��ջ����Ų��ֽڵ㣬size()С������h

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