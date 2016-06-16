/**@TITLE:Copy List with Random Pointer(���������ָ�������)
 * 		A linked list is given such that each node contains an additional 
 * 		random pointer which could point to any node in the list or null.
 *		Return a deep copy of the list.
 * @TIME:2015-7-4
 * @FROM:leetcode
 * @TYPE����������/��ϣ��
 * @author ShaoCheng
 */
package leetcode;

import java.util.HashMap;
import java.util.Iterator;

/**˼·1:�����������������裺
 * 		1.����ÿһ���ڵ㣬������ָ����һ�����磬1->2->3->4������֮��1->1->2->2->3->4
 * 		2.����randomָ��
 * 		3.�ֲ�����
 * �㷨���ܣ����ŵ��㷨���ܣ�ʱ�临�Ӷ�O(n)���ռ�����O(1)
 */
class Solution_1 { //ÿһ��java�ļ���ֻ����һ��public��
    public RandomListNode copyRandomList(RandomListNode head) {
    	if(head == null)
    		return null;
        RandomListNode node1 = head;
        RandomListNode node2 = null;
        
        //����
        while(node1 != null){
        	RandomListNode tmp = node1.next; //������һ���ڵ������
        	node2 = new RandomListNode(node1.label); //����һ�������ڵ�
        	node2.next = tmp;
        	node1.next = node2;
        	
        	/*�ⲿ�ִ��������⣬ֻ�ܴ���random���������������֮ǰ�Ľڵ㣬
        	 * ������ù�����Ľڵ����ڱ���ѭ�����޷�����*/
//        	if(node1.random != null) //�̶�random����
//        		node2.random = node1.random.next;
        	
        	node1 = tmp; //����
        }
        
        //�������random���õĸ��ƣ���������ǰ�棬�Լ�������Ľڵ�
        node1 = head;
        while(node1 != null){
        	if(node1.random != null)
        		node1.next.random = node1.random.next;
        	node1 = node1.next.next;
        }
        
        //���뿽��
        node1 = head;
        RandomListNode head2 = head.next;
        node2 = head.next;
        while(node2 != null){
        	node1.next = node2.next;
        	node1 = node1.next;
        	
        	if(node1 == null)
        		break;
        	node2.next = node1.next;
        	node2 = node2.next;
        }
        return head2;
    }
}

/**˼·2��ʹ�ù�ϣ����һ�α���������ÿһ�ڵ㣬ʹ�ù�ϣ�����¾ɽڵ��ӳ���ϵ<old, new>
 * 		�ڶ�����������randomָ���򣬽����ҵ�old.randomָ����ָ�Ľڵ㣬�ٲ�ѯ��ϣ��
 * ���ܣ�ʱ�临�Ӷ�O(n)�� �ռ临�Ӷ�O(n)��
 */
public class Solution{
	public RandomListNode copyRandomList(RandomListNode head) {
		if(head == null)
			return null;
		RandomListNode new_head = null;
		RandomListNode node1 = head, node2 = null;
		HashMap<RandomListNode, RandomListNode> hmap = new HashMap<RandomListNode, RandomListNode>();
		while(node1 != null){
			if(new_head == null){
				new_head = new RandomListNode(node1.label);
				node2 = new_head;
			}
			else{
				node2.next = new RandomListNode(node1.label);
				node2 = node2.next;
			}
			hmap.put(node1, node2); //����¡��ɽڵ��ӳ���ϵ
			node1 = node1.next;
		}

		node1 = head;
		while(node1 != null){
			if(node1.random != null){
				RandomListNode var = hmap.get(node1);
				var.random = hmap.get(node1.random);
			}
			node1 = node1.next;
		}
		return new_head;
	}
}

//Definition for singly-linked list with a random pointer.
class RandomListNode {
	int label;
	RandomListNode next, random;
	RandomListNode(int x) { this.label = x; }
};