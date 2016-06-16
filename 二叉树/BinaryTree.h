// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

// 只要在头文件开始加入这条指令就能保证头文件只被编译一次
// 防止某个头文件被多次#include/#define/#ifndef/#endif
#pragma once
#include <iostream>
using namespace std;
#define LEETCODE_TREE
/* LEETCODE上的树结构, 保持代码的兼容性 */
#ifdef LEETCODE_TREE
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(){}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef struct TreeNode BinaryTreeNode;
//#define BinaryTreeNode TreeNode
#define m_nValue val
#define m_pLeft left
#define m_pRight right

#else /* 剑指offer上的树结构 */
struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
};
#endif

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(BinaryTreeNode* pNode);
void PrintTree(BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
