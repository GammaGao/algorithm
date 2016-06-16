package leetcode;

/**
 * @tile Swap Nodes in Pairs(成对交换链表中相邻两个节点)
 * 		Given a linked list, swap every two adjacent nodes and return its head.
 * 		For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 		Your algorithm should use only constant space. You may not modify the 
 * 		values in the list, only nodes itself can be changed.
 * @time 2015-7-26
 * @from leetcode
 * @type linked list
 * @author ShaoCheng
 */
//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**
 * @思路：成对交换相邻两个节点，注意区分链表头和非链表头就行
 * @性能：时间复杂度O(n)，空间复杂度O(1)
 * @author ShaoCheng
 *
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null)
        	return null;
        ListNode p1 = head;
        ListNode last = null;
        while(p1 != null){
        	ListNode p2 = p1.next;
        	if(p2 == null) //单节点或者奇数节点会从此退出
        		return head;
        	if(p1 == head){ //交换节点有表头
        		p1.next = p2.next;
        		p2.next = p1;
        		head = p2;
        		last = p1;
        	}
        	else{ //无表头
        		p1.next = p2.next;
        		p2.next = p1;
        		last.next = p2;
        		last = p1;
        	} //交换完成后，p1与p2换位置了
        	p1 = p1.next; //移动到下一对，但保持p1在后，p2在前
        }
        return head;
    }
}
