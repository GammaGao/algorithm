/* 题目：输入一棵二叉搜索树BST，将BST转换成一棵排序的双向链表。要求不能创建任何新的节点，
 *		只能调整树中结点的指针的指向。
 * TIME：2015-5-4
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* 获取双向链表的尾结点 */
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

/* 思路： 对于如下所示的树，我们先分析结点10，假设左子树已经转换成双向链表，右子树已经转换成双向链表。那么只需要处理这三部分连接即可。
 *            10
 *         /      \
 *        6        14
 *       /\        /\
 *      4  8     12  16
 *		按上述过程递归的处理左右子树。
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

	if (tail == NULL && rightSubHead == NULL) //左右子链表均为空
		return root;
	else if (tail == NULL){ //左子链表为空
		//root->m_pLeft = NULL;
		root->m_pRight = rightSubHead;
		rightSubHead->m_pLeft = root;
		return root;
	}
	else if (rightSubHead == NULL){ //右子链表为空
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

// ====================测试代码====================
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

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1);

	DestroyList(pNode1);
}

// 树中没有结点
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