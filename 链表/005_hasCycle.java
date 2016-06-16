package leetcode;
/**
 * @title Linked List Cycle(�жϵ�������û�л�)
 * 		Given a linked list, determine if it has a cycle in it.
 *		Follow up:
 *		Can you solve it without using extra space?
 * @author ShaoCheng
 * @time 2015-7-25
 * @from leetcode
 * @type Linked List(������)
 */

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**˼·����������л��Ļ�����ô���ʵ�ָ�����޷��߳�ȥ�ģ���˿���ʹ�ÿ���ָ��ġ�
 * 		����ָ�������һ�����ڻ��С�
 * 
 * ���ܣ�ʱ�临�Ӷ�O(1), �ռ临�Ӷ�O(1)
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null)
        	return false;
        ListNode fast = head; //��ָ�룬ÿ���ƶ������ڵ�
        ListNode slow = head; //��ָ�룬ÿ���ƶ�һ���ڵ�
        while(fast != null && fast.next != null){
        	slow = slow.next;
        	fast = fast.next.next;
        	if(slow == fast)
        		return true;
        }
        return false;
    }
}
