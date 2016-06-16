/* @TITLE: Convert Sorted List to Binary Search Tree
 *		Given a singly linked list where elements are sorted in ascending order,
 *		convert it to a height balanced BST.
 *
 * @TIME:2015-6-1
 * @TYPE:DFS
 * @FROM:Leetcode
 * @AUTHOR:PengSc
 */
#include <iostream>
#include "BinaryTree.h"
#include "List.h"
using namespace std;

/* �ѵ�����ת����ƽ��BST��������ʽ��Ψһ���磬1->2->3->4->5
 *		2			3			3			3			3			4
 *	   / \		   / \		   / \		   / \		   / \		   / \
 *	  1   4       2   4       1   5       2   5		  1   4		  2   5
 *		 / \     /	   \       \   \     /   /         \   \     / \
 *		3   5   1       5       2   4   1   4			2   5   1   3
 *	����ʲô��ʽ��ȡ���ڲ�ȡ���㷨���ԡ�
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		return sortedListToBST(head, NULL);
	}
private:
	TreeNode* sortedListToBST(ListNode *head, ListNode *tail)
	{
		if (head == NULL || head == tail)
			return NULL;
		if (head->next == tail)
			return new TreeNode(head->val);
		ListNode * mid = findMidddleOfList(head, tail);
		TreeNode *root;
		if (mid)
			 root = new TreeNode(mid->val);
		else
			return NULL;
		TreeNode *left_subtree = sortedListToBST(head, mid);
		TreeNode *right_subtree = sortedListToBST(mid->next, tail);
		root->left = left_subtree;
		root->right = right_subtree;
	}
public:
	/* ���ҵ�����head���м�ڵ㣨β�ڵ㲻����tail�ڵ㣬ʵ�����ҵ���head��tailǰһ���ڵ����м�ڵ㣩 */
	ListNode* findMidddleOfList(ListNode* head, ListNode *tail)
	{
		if (head == NULL || head == tail)
			return NULL;
		if (head->next == tail)
			return head;
		ListNode *p1, *p2;
		p1 = head;
		p2 = head;
		while (p2->next != NULL && p2->next != tail
			&& p2->next->next != NULL && p2->next->next != tail){
			p1 = p1->next;
			p2 = p2->next->next;
		}
		return p1;
	}
};

int main()
{
	Solution sl;
	ListNode *p1 = CreateListNode(1);
	ListNode *p2 = CreateListNode(2);
	ListNode *p3 = CreateListNode(3);
	ListNode *p4 = CreateListNode(4);
	ListNode *p5 = CreateListNode(5);
	ListNode *p6 = CreateListNode(6);
	ConnectListNodes(p1, p2);
	ConnectListNodes(p2, p3);
	ConnectListNodes(p3, p4);
	ConnectListNodes(p4, p5);
	ConnectListNodes(p5, p6);
	TreeNode *res = sl.sortedListToBST(p1);
	PrintTree(res);
	DestroyTree(res);
	//ListNode *r = sl.findMidddleOfList(p1, p5);
	//cout << r->val << endl;
	system("pause");
}