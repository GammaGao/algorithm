/* @TITLE: Construct Binary Tree from Preorder and Inorder Traversal
 *		Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:You may assume that duplicates do not exist in the tree.(如果有重复节点，那么不能唯一的确定一颗树)
 * 
 * @TIME:2015-6-1
 * @TYPE:leetcode
 * @From:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//“简单”判断是合法输入，这种判断方法是不完全的，因为当preorder和inorder集合中如果有相异的元素
		//那么，输入是不合法的。但在leetcode上测试，默认输入时合法，故没加进行此判断
		if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
			return NULL;
		int root_index = 0; //指示preorder当前节点的位置
		return buildTree(preorder, root_index, inorder, 0, inorder.size()-1);
	}
private:
	TreeNode* buildTree(vector<int> &preorder, int &root_index, vector<int> &inorder, int start, int end)
	{
		if (start > end)
			return NULL;
		if (start == end){
			root_index++;
			return new TreeNode(inorder.at(start));
		}
		//找到下一个root节点的索引mid
		int mid = FindRootIndexInOrder(inorder, preorder.at(root_index));
		root_index++;
		TreeNode *left_subtree = buildTree(preorder, root_index, inorder, start, mid-1); //左子树
		TreeNode *right_subtree = buildTree(preorder, root_index, inorder, mid+1, end); //右子树
		TreeNode *root = new TreeNode(inorder.at(mid));
		root->left = left_subtree;
		root->right = right_subtree;
		return root;
	}
	int FindRootIndexInOrder(vector<int> &inorder, int key)
	{
		int i = 0;
		while (i < inorder.size() && key != inorder.at(i))
			i++;
		return i;
	}
};

int main()
{
	Solution sl;
	//      1
	//     / \
	//    2   3
	//   /   / \
	//  4   5   6
	//   \     /
	//	  7   8
	//vector<int> preorder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	//vector<int> inorder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	//	1
	//vector<int> preorder = { 1 };
	//vector<int> inorder = { 1 };

	// 1
	//  \
	//   2
	//vector<int> preorder = { 1, 2 };
	//vector<int> inorder = { 1, 2 };

	//	1
	// /
	//2
	vector<int> preorder = { 1, 2 };
	vector<int> inorder = { 2, 1 };
	TreeNode *root = sl.buildTree(preorder, inorder);
	PrintTree(root);
	DestroyTree(root);
	system("pause");
}