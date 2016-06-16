/* TITLE£ºRemove all elements from a linked list of integers that have value val.
 * Example Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * TIME£º2015-5-7
 * FROM£ºleetcode
 */
#include <iostream>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *p = head, *pre;
		pre = NULL;
		while (p){
			if (p->val == val && p == head){
				head = p->next;
				delete p;
				p = head;
			}
			else if (p->val == val){
				pre->next = p->next;
				delete p;
				p = pre->next;
			}
			else{
				pre = p;
				p = p->next;
			}
		}
		return head;
	}
};

void print(ListNode *head)
{
	ListNode *p = head;
	if (head == NULL)
		cout << "none" << endl;
	while (p){
		cout << p->val << ",";
		p = p->next;
	}
}

ListNode* CreateList(int a[], int n)
{
	ListNode *head, *p;
	int i = 0;
	if (a == NULL || n < 0)
		return NULL;

	head = new ListNode(a[i]);
	head->val = a[0];
	p = head;
	for (i = 1; i < n; i++){
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	return head;
}

int main()
{
	Solution s;
	ListNode *in, *out;

	//int a[] = { 1 };
	//int a[] = {1, 2, 1};
	int a[] = {1, 1, 1, 4};
	in = CreateList(a, sizeof(a)/sizeof(int));
	out = s.removeElements(in, 1);
	print(out);
	system("pause");
}