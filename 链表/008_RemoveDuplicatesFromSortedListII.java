package leetcode;

/**
 * title - Remove Duplicates from Sorted List II
 * 		Given a sorted linked list, delete all nodes that have duplicate numbers,
 * 		leaving only distinct numbers from the original list.
 * 		For example,
 * 		Given 1->2->3->3->4->4->5, return 1->2->5.
		Given 1->1->1->2->3, return 2->3.
 * @author ShaoCheng
 * @version 1.0
 * time 2015-8-17
 */
//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
        	return null;
        ListNode p = head;
        ListNode pre = null;
        while(p != null){
        	ListNode pNext = p.next;
        	boolean needDelete = false;
        	if(pNext != null && pNext.val == p.val)
        		needDelete = true;
        	if(!needDelete){
        		pre = p;
        		p = pNext;
        	}
        	else{ //删除
        		int val = p.val; //保存要删除节点的值
        		while(pNext != null && pNext.val == val){
        			pNext = pNext.next;
//        			p.next = pNext;
        		}
        		if(pre != null){
        			pre.next = pNext;
        		}
        		else
        			head = pNext;
        		p = pNext;
        	}
        }
        return head;
    }
}