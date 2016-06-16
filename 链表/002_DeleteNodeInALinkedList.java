/**@TITLE:Delete Node in a Linked List(ɾ���������е�һ���ڵ�)
 * 		Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *		Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
 *		should become 1 -> 2 -> 4 after calling your function.
 * @TIME:2015-7-19
 * @TYPE:������
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

/**˼·������ֻ��һ����ɾ���Ľڵ����������޷��ҵ�ǰ���ڵ㣬
 * 		��ֻ�ܰ���һ���ڵ��ֵ��������ǰ�ڵ㣬Ȼ����ɾ����һ���ڵ�
 * ���ܣ�ʱ�临�Ӷ�O(1)���ռ临�Ӷ�O(1).
 */
public class Solution {
    public void deleteNode(ListNode node) {
        if(node == null || node.next == null) //���Ϊ�ջ���Ϊβ�ڵ�
        	return;
        ListNode nextNode = node.next; //�ҵ���һ���ڵ�
        node.val = nextNode.val; //����ֵ
        node.next = nextNode.next; //ɾ����һ���ڵ�
    }
}
