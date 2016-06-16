package leetcode;

/**
 * @tile Swap Nodes in Pairs(�ɶԽ������������������ڵ�)
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
 * @˼·���ɶԽ������������ڵ㣬ע����������ͷ�ͷ�����ͷ����
 * @���ܣ�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
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
        	if(p2 == null) //���ڵ���������ڵ��Ӵ��˳�
        		return head;
        	if(p1 == head){ //�����ڵ��б�ͷ
        		p1.next = p2.next;
        		p2.next = p1;
        		head = p2;
        		last = p1;
        	}
        	else{ //�ޱ�ͷ
        		p1.next = p2.next;
        		p2.next = p1;
        		last.next = p2;
        		last = p1;
        	} //������ɺ�p1��p2��λ����
        	p1 = p1.next; //�ƶ�����һ�ԣ�������p1�ں�p2��ǰ
        }
        return head;
    }
}
