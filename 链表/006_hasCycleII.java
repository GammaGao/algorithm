package leetcode;
/**
 * @tile Linked List Cycle II(Ѱ�ҵ��������)
 * 		Given a linked list, return the node where the cycle begins.
 * 		If there is no cycle, return null.
 * @time 2015-7-25
 * @from leetcode
 * @type linked list(������)
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

/**˼·�����ҵ�����ں󣬵�����ָ��ָ�������ͷ���ٶȵ���Ϊÿ���ƶ�1���ڵ㣬��ָ��λ�ò���
 * 		���ٴ�����ָ������ʱ�����ǻ���ڵ㡣���Դ���ѧ��֤��������ȷ�ġ������ݲ�֤����
 * ���ܣ�ʱ�临�Ӷ�O(n), �ռ临��O(1)
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null)
        	return null;
        ListNode fast = head; //��ָ�룬ÿ���ƶ������ڵ�
        ListNode slow = head; //��ָ�룬ÿ���ƶ�һ���ڵ�
        while(fast != null && fast.next != null){
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast){ //�ҵ���, Ѱ����ڵ�
        		//����fastָ��λ�ü����ƶ��ٶ�
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