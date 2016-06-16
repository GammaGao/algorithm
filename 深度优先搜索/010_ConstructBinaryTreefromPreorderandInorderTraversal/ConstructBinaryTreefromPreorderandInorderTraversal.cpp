/* @TITLE: Construct Binary Tree from Preorder and Inorder Traversal
 *		Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:You may assume that duplicates do not exist in the tree.(������ظ��ڵ㣬��ô����Ψһ��ȷ��һ����)
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
		//���򵥡��ж��ǺϷ����룬�����жϷ����ǲ���ȫ�ģ���Ϊ��preorder��inorder����������������Ԫ��
		//��ô�������ǲ��Ϸ��ġ�����leetcode�ϲ��ԣ�Ĭ������ʱ�Ϸ�����û�ӽ��д��ж�
		if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
			return NULL;
		int root_index = 0; //ָʾpreorder��ǰ�ڵ��λ��
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
		//�ҵ���һ��root�ڵ������mid
		int mid = FindRootIndexInOrder(inorder, preorder.at(root_index));
		root_index++;
		TreeNode *left_subtree = buildTree(preorder, root_index, inorder, start, mid-1); //������
		TreeNode *right_subtree = buildTree(preorder, root_index, inorder, mid+1, end); //������
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