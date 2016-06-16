package leetcode;
/**
 * @tile Linked List Cycle II(寻找单链表环入口)
 * 		Given a linked list, return the node where the cycle begins.
 * 		If there is no cycle, return null.
 * @time 2015-7-25
 * @from leetcode
 * @type linked list(单链表)
 * @author ShaoCheng
 */

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

/**思路：当找到环入口后，调整快指针指向单链表表头，速度调整为每次移动1个节点，慢指针位置不动
 * 		当再次与慢指针相遇时，就是环入口点。可以从数学上证明这是正确的。这里暂不证明。
 * 性能：时间复杂度O(n), 空间复杂O(1)
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null)
        	return null;
        ListNode fast = head; //快指针，每次移动两个节点
        ListNode slow = head; //慢指针，每次移动一个节点
        while(fast != null && fast.next != null){
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast){ //找到环, 寻找入口点
        		//调整fast指针位置及其移动速度
        		fast = head;
        		while(fast != slow){
        			fast = fast.next;
        			slow = slow.next;
        		}
        		return fast;
        	}
        }
        return null;
    }
}