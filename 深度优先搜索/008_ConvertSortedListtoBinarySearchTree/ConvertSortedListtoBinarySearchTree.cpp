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

/* 把单链表转换成平衡BST树，其形式不唯一，如，1->2->3->4->5
 *		2			3			3			3			3			4
 *	   / \		   / \		   / \		   / \		   / \		   / \
 *	  1   4       2   4       1   5       2   5		  1   4		  2   5
 *		 / \     /	   \       \   \     /   /         \   \     / \
 *		3   5   1       5       2   4   1   4			2   5   1   3
 *	具体什么形式，取决于采取的算法策略。
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
	/* 查找单链表head到中间节点（尾节点不包括tail节点，实际上找的是head到tail前一个节点间的中间节点） */
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