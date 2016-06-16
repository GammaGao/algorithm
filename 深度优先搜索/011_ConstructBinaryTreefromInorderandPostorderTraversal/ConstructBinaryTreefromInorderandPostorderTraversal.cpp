/* @TITLE: Construct Binary Tree from Inorder and Postorder Traversal
 *		Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note:
 *		You may assume that duplicates do not exist in the tree.
 *
 * @TIME:2015-6-2
 * @TYPE:DFS
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

/* ˼·ͬ����������ת��������
 */
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size())
			return NULL;
		int root_depth = postorder.size() - 1;//�������һ���ڵ�
		return buildTree(inorder, 0, inorder.size() - 1, postorder, root_depth);
	}
private:
	TreeNode *buildTree(vector<int>& inorder, int start, int end, vector<int> &postorder, int &root_depth)
	{
		if (start > end)
			return NULL;
		if (start == end){
			root_depth--;
			return new TreeNode(inorder.at(start));
		}
		int mid = FindRootIndexInOrder(inorder, start, end, postorder.at(root_depth));
		root_depth--;
		TreeNode *right_subtree = buildTree(inorder, mid + 1, end, postorder, root_depth); //�ȹ�������
		TreeNode *left_subtree = buildTree(inorder, start, mid - 1, postorder, root_depth);//�ٹ�������
		TreeNode *root = new TreeNode(inorder.at(mid));
		root->left = left_subtree;
		root->right = right_subtree;
	}

	/* ����������в����������ڵ㣬 ����ʱ����ÿ�ζ���������inorder(����������ת�������У�����ô����) */
	int FindRootIndexInOrder(vector<int>& inorder, int start, int end, int key)
	{
		int i = end;
		while (i >= start && inorder.at(i) != key)
			i--;
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
	vector<int> postorder = { 7, 4, 2, 5, 8, 6, 3, 1 };
	vector<int> inorder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	//	1
	//vector<int> postorder = { 1 };
	//vector<int> inorder = { 1 };

	// 1
	//  \
	//   2
	//vector<int> postorder = { 2, 1 };
	//vector<int> inorder = { 1, 2 };

	//	1
	// /
	//2
	//vector<int> postorder = { 2, 1 };
	//vector<int> inorder = { 2, 1 };
	TreeNode *root = sl.buildTree(inorder, postorder);
	PrintTree(root);
	DestroyTree(root);
	system("pause");
}