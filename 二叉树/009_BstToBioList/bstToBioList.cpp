/* ��Ŀ������һ�ö���������BST����BSTת����һ�������˫������Ҫ���ܴ����κ��µĽڵ㣬
 *		ֻ�ܵ������н���ָ���ָ��
 * TIME��2015-5-4
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* ��ȡ˫�������β��� */
BinaryTreeNode *getBioListTail(BinaryTreeNode *head)
{
	BinaryTreeNode *p = head;
	if (p == NULL)
		return p;
	while (p->m_pRight){
		p = p->m_pRight;
	}
	return p;
}

/* ˼·�� ����������ʾ�����������ȷ������10�������������Ѿ�ת����˫�������������Ѿ�ת����˫��������ôֻ��Ҫ���������������Ӽ��ɡ�
 *            10
 *         /      \
 *        6        14
 *       /\        /\
 *      4  8     12  16
 *		���������̵ݹ�Ĵ�������������
 */
BinaryTreeNode *bstToBiolist(BinaryTreeNode *root)
{
	if (root == NULL)
		return NULL;
	BinaryTreeNode *leftSubHead, *rightSubHead;
	BinaryTreeNode *tail;
	leftSubHead = bstToBiolist(root->m_pLeft);
	rightSubHead = bstToBiolist(root->m_pRight);
	tail = getBioListTail(leftSubHead);

	if (tail == NULL && rightSubHead == NULL) //�����������Ϊ��
		return root;
	else if (tail == NULL){ //��������Ϊ��
		//root->m_pLeft = NULL;
		root->m_pRight = rightSubHead;
		rightSubHead->m_pLeft = root;
		return root;
	}
	else if (rightSubHead == NULL){ //��������Ϊ��
		tail->m_pRight = root;
		root->m_pLeft = tail;
		//root->m_pRight = NULL;
		return leftSubHead;
	}
	else{
		tail->m_pRight = root;
		root->m_pLeft = tail;
		root->m_pRight = rightSubHead;
		rightSubHead->m_pLeft = root;
		return leftSubHead;
	}
}

// ====================���Դ���====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	printf("The nodes from left to right are:\n");
	while (pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pRight == NULL)
			break;
		pNode = pNode->m_pRight;
	}

	printf("\nThe nodes from right to left are:\n");
	while (pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pLeft == NULL)
			break;
		pNode = pNode->m_pLeft;
	}

	printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;
	while (pNode != NULL)
	{
		BinaryTreeNode* pNext = pNode->m_pRight;

		delete pNode;
		pNode = pNext;
	}
}

void Test(char *testName, BinaryTreeNode *pRootOfTree)
{
	if (testName != NULL)
		printf("%s test begin:\n", testName);
	PrintTree(pRootOfTree);
	BinaryTreeNode *pHeadOfList = bstToBiolist(pRootOfTree);
	PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	Test("Test01", pNode10);
	DestroyList(pNode4);
}


//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
	BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, NULL);
	ConnectTreeNodes(pNode4, pNode3, NULL);
	ConnectTreeNodes(pNode3, pNode2, NULL);
	ConnectTreeNodes(pNode2, pNode1, NULL);

	Test("Test2", pNode5);
	DestroyList(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, NULL, pNode2);
	ConnectTreeNodes(pNode2, NULL, pNode3);
	ConnectTreeNodes(pNode3, NULL, pNode4);
	ConnectTreeNodes(pNode4, NULL, pNode5);

	Test("Test3", pNode1);

	DestroyList(pNode1);
}

// ����ֻ��1�����
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1);

	DestroyList(pNode1);
}

// ����û�н��
void Test5()
{
	Test("Test5", NULL);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	system("pause");
}