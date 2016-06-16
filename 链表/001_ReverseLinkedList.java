/**@TITLE:Reverse Linked List����ת������
 * 		Reverse a singly linked list.
 * @TYPE:����
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

/**˼·����ת�������õ�����ָ��
 * ���ܣ�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
    	if(head == null)
    		return null;
        ListNode p = head;
        ListNode q = p.next;
        while(p.next != null){
            ListNode r = q.next; //ָ��ָ����ǰ
        	q.next = p; //��ת
        	if(r == null){ //ѭ����������
        		head.next = null; //�����˴���head.next
        		return q; //ͨ������q
        	}
        	p = q; //�ƶ�ָ����
        	q = r;
        }
        head.next = null;
        return head; //ֻ��һ���ڵ�Ż᷵��head
    }
}
