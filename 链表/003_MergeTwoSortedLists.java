/**@TITLE:Merge Two Sorted Lists(�ϲ�����������)
 * 		Merge two sorted linked lists and return it as a new list. 
 * 		The new list should be made by splicing together the nodes 
 * 		of the first two lists.
 * @TYPE:������
 * @TIME:2015-7-19
 * @FROM:leetcode
 * @author ShaoCheng
 */
package leetcode;

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null)
        	return l2;
        if(l2 == null)
        	return l1;
        
        ListNode head = null;
        ListNode p = null; //ָ��ϲ���������β�ڵ�
        while(l1 != null && l2 != null){
        	if(head == null){ //�ҵ�ͷ�ڵ�
        		if(l1.val < l2.val){
        			head = l1;
        			l1 = l1.next;
        		}
        		else{
        			head = l2;
        			l2 = l2.next;
        		}
        		p = head;
        	}
        	while(l1 != null && l2 != null && l1.val < l2.val){ //��������1�б�����2��С��Ԫ��
        		p.next = l1;
        		p = p.next;
        		l1 = l1.next;
        	}
        	while(l1 != null && l2 != null && l1.val >= l2.val){ //��������1�б�����2��С��Ԫ��
        		p.next = l2;
        		p = p.next;
        		l2 = l2.next;
        	}
        }
    	if(l1 == null){
    		p.next = l2;
    	}
    	if(l2 == null){
    		p.next = l1;
    	}
        return head;
    }
}
