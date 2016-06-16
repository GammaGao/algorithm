package leetcode;

/**@TITLE:Palindrome Linked List(判断单链表是否是回文链表)
 *      Given a singly linked list, determine if it is a palindrome.
 *      Follow up:
 *      Could you do it in O(n) time and O(1) space?
 * @TIME:2015-7-25
 * @TYPE:Linked List(单链表)
 * @FROM:leetcode
 * @author ShaoCheng
 */
//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**思路：如果不考虑空间复杂度，那么可以直接创造另一个单链表，再反转链表。
 *      但是如果要求时间复杂度O(n)，空间复杂度O(1)，那么只能在所给出的单链表上操作。
 *      思路是，反转一半的链表。
 */
public class IsPalindrome {
    public boolean isPalindrome(ListNode head) {
    	if(head == null)
    		return true;
    	int n = ListSize(head);
    	ListNode p = head;
    	int k = 0;
    	while(k < (n+1)/2){
    		p = p.next;
    		k++;
    	}
    	ListNode secondHead = p; //找到第二个链表表头
    	
    	ListNode firstHead = ReverseList(head, n/2); //反转前一半的链表
    	while(firstHead != null && secondHead != null){
    		if(firstHead.val != secondHead.val)
    			return false;
    		firstHead = firstHead.next;
    		secondHead = secondHead.next;
    	}
    	return true;
    }

    //反转链表， 但注意它不是反转整个链表，只是反转一半的链表
    public ListNode ReverseList(ListNode head, int n){
    	if(head == null || n <= 0)
    		return null;
    	if(head.next == null)
    		return head;
    	ListNode p1 = head;
    	ListNode p2 = head.next;
    	int k = 1;
    	while(p2 != null){
    		k++;
    		if(k > n)
    			break;
    		ListNode p3 = p2.next;
    		p2.next = p1;
    		p1 = p2;
    		p2 = p3;
    		if(p3 == null)
    			break;
    	}
    	head.next = null;
    	return p1;
    }

    //单链表的长度
    public int ListSize(ListNode head){
    	int n = 0;
    	if(head == null)
    		return 0;
    	ListNode p = head;
    	while(p != null){
    		n++;
    		p = p.next;
    	}
    	return n;
    }
}
