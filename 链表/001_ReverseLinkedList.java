/**@TITLE:Reverse Linked List（反转单链表）
 * 		Reverse a singly linked list.
 * @TYPE:链表
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

/**思路：反转单链表用到三个指针
 * 性能：时间复杂度O(n),空间复杂度O(1)
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
    	if(head == null)
    		return null;
        ListNode p = head;
        ListNode q = p.next;
        while(p.next != null){
            ListNode r = q.next; //指针指向最前
        	q.next = p; //反转
        	if(r == null){ //循环结束条件
        		head.next = null; //别忘了处理head.next
        		return q; //通常返回q
        	}
        	p = q; //移动指针域
        	q = r;
        }
        head.next = null;
        return head; //只有一个节点才会返回head
    }
}
