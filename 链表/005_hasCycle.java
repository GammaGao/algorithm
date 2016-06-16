package leetcode;
/**
 * @title Linked List Cycle(判断单链表有没有环)
 * 		Given a linked list, determine if it has a cycle in it.
 *		Follow up:
 *		Can you solve it without using extra space?
 * @author ShaoCheng
 * @time 2015-7-25
 * @from leetcode
 * @type Linked List(单链表)
 */

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**思路：如果链表有环的话，那么访问的指针是无法走出去的，因此可以使用快慢指针的。
 * 		快慢指针的相遇一定是在环中。
 * 
 * 性能：时间复杂度O(1), 空间复杂度O(1)
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null)
        	return false;
        ListNode fast = head; //快指针，每次移动两个节点
        ListNode slow = head; //慢指针，每次移动一个节点
        while(fast != null && fast.next != null){
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast)
        		return true;
        }
        return false;
    }
}
