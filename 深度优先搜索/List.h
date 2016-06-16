// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛
#include <iostream>
#define LEETCODE_LIST
#ifdef LEETCODE_LIST
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(){}
	ListNode(int x) : val(x), next(NULL) {}
};
#define m_nValue val
#define m_pNext next
#else
struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};
#endif

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);