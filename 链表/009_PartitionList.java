package leetcode;

/**
 * @title Partition List
 * 		Given a linked list and a value x, partition it such that all nodes less
 * 		than x come before nodes greater than or equal to x. You should preserve
 * 		the original relative order of the nodes in each of the two partitions.
 * 		(ע�⣺��С��x�������ŵ� ���ڵ���x��ǰ��)
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
 * ˼·�����ǲ�����һ���������н������������鷳����������α�ڵ�lhead, rhead��������������ֱ𱣴�
 * 		С��x�Ľڵ㣬���ڵ���x�Ľڵ㡣�����һ�¼��ɡ�
 * ���ܣ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
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