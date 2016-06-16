// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

// ֻҪ��ͷ�ļ���ʼ��������ָ����ܱ�֤ͷ�ļ�ֻ������һ��
// ��ֹĳ��ͷ�ļ������#include/#define/#ifndef/#endif
#pragma once

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(BinaryTreeNode* pNode);
void PrintTree(BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
