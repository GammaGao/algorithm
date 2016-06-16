package leetcode;

/**
 * @title Partition List
 * 		Given a linked list and a value x, partition it such that all nodes less
 * 		than x come before nodes greater than or equal to x. You should preserve
 * 		the original relative order of the nodes in each of the two partitions.
 * 		(注解：把小于x的数都放到 大于等于x的前面)
 *		For example, Given 1->4->3->2->5->2 and x = 3,
 *		return 1->2->2->4->3->5.
 * @author ShaoCheng
 * @time 2015-8-18
 */

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**
 * 思路：并非采用在一个单链表中交换，这样很麻烦。建立两个伪节点lhead, rhead组成两个单链表，分别保存
 * 		小于x的节点，大于等于x的节点。再组合一下即可。
 * 性能：时间复杂度O(n)，空间复杂度O(1)
 * @author ShaoCheng
 *
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
    	if(head == null)
    		return null;
    	ListNode lhead = new ListNode(0);
    	ListNode rhead = new ListNode(0);
    	ListNode l = lhead, r = rhead;
    	
    	ListNode p = head;
        while(p != null){
        	if(p.val < x){
        		l.next = p;
        		l = l.next;
        	}
        	else{
        		r.next = p;
        		r = r.next;
        	}
        	p = p.next;
        }
        r.next = null;
        l.next = rhead.next;
        head = lhead.next;
        
        return head;
    }
}