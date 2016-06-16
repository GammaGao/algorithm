// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

// ֻҪ��ͷ�ļ���ʼ��������ָ����ܱ�֤ͷ�ļ�ֻ������һ��
// ��ֹĳ��ͷ�ļ������#include/#define/#ifndef/#endif
#pragma once
#include <iostream>
using namespace std;
#define LEETCODE_TREE
/* LEETCODE�ϵ����ṹ, ���ִ���ļ����� */
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

#else /* ��ָoffer�ϵ����ṹ */
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
