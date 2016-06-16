/**@TITLE:Delete Node in a Linked List(删除单链表中的一个节点)
 * 		Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *		Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
 *		should become 1 -> 2 -> 4 after calling your function.
 * @TIME:2015-7-19
 * @TYPE:单链表
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

/**思路：由于只有一个被删除的节点作参数，无法找到前驱节点，
 * 		故只能把下一个节点的值拷贝到当前节点，然后再删除下一个节点
 * 性能：时间复杂度O(1)，空间复杂度O(1).
 */
public class Solution {
    public void deleteNode(ListNode node) {
        if(node == null || node.next == null) //如果为空或者为尾节点
        	return;
        ListNode nextNode = node.next; //找到下一个节点
        node.val = nextNode.val; //拷贝值
        node.next = nextNode.next; //删除下一个节点
    }
}
