/* @TITLE: Count Complete Tree Nodes(计算完全二叉树的节点数)
 *		Given a complete binary tree, count the number of nodes.
 * @TIME:2015-6-15
 * @TYPE:Binary Search
 * @FROM:leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
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

/* 以下思路：树高为h的完全二叉树的节点数2^(h-1)-1到2^h - 1个之间，
 *		因此先求出树高，再求最底层的树叶子点的数目。
 * 性能：由于是遍历二叉树，其时间复杂度为O(n)，其中n为节点数目。
 * 更优算法：时间复杂度O(logn)
 */
class Solution_1 {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		int h = height(root);
		int count = 0;
		int hh = 1;
		preorder(root, hh, h, count);
		return pow(2, h - 1) + count - 1;
	}
private:
	int height(TreeNode *root){ //求出树的高度, 其时间复杂度也为O(n)
		if (root == NULL)
			return 0;
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	void preorder(TreeNode *root, int hh, int h, int &count){ //先序遍历找h-1层叶子数
		if (root){
			if (hh == h - 1 && root->left && root->right)
				count += 2;
			else if (hh == h - 1 && (root->left || root->right))
				count += 1;
			preorder(root->left, hh+1, h, count);
			preorder(root->right, hh+1, h, count);
		}
	}
};

/* 思路：充分借鉴二分查找算法的思想，二分查找本质上是查找BST树，计算完全二叉树所有节点并非要遍历整个树
 *		如果一颗高度的满二叉树，其节点个数是2^n - 1, 因此其思想是把整个树每次二分形成更小的二叉树。
 */
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftHeigth = lheight(root->left);
		int rightHeight = rheight(root->right);
		if (leftHeigth == rightHeight) //可以快速判断是满完全二叉树
			return pow(2, leftHeigth + 1) - 1;
		else// if (leftHeigth > rightHeight){ //并非满完全二叉树
			return countNodes(root->left) + countNodes(root->right) + 1;
		//}
		//else if (leftHeigth < rightHeight) //对于完全二叉树而言，不会出现这种情况
	}
private:
	int lheight(TreeNode *root){
		int h = 0;
		while (root){
			h++;
			root = root->left;
		}
		return h;
	}
	int rheight(TreeNode *root){
		int h = 0;
		while (root){
			h++;
			root = root->right;
		}
		return h;
	}
};

/* 以下是别人更为清晰的代码
 */
class Solution_other {
public:
    int countNodes(TreeNode* root) {
        int tmp = isComplete(root);
        if (tmp != -1) return tmp;
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return 1 + l + r;
    }
private:
    int isComplete(TreeNode* root)
    {
        if (!root) return 0;
        TreeNode * l, *r;
        l = r = root;
        int h = 1;
        while (l&&r)
        {
            l = l->left;
            r = r->right;
            h*=2;
        }
        if (l || r) return -1;
        return h - 1;
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
	ConnectTreeNodes(p1, p2, p3);
	ConnectTreeNodes(p2, p4, p7);
	ConnectTreeNodes(p3, p5, p6);

	Solution sl;
	cout << sl.countNodes(p1) << endl;
	DestroyTree(p1);
	system("pause");
}