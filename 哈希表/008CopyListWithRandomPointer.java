/**@TITLE:Copy List with Random Pointer(拷贝带随机指针的链表)
 * 		A linked list is given such that each node contains an additional 
 * 		random pointer which could point to any node in the list or null.
 *		Return a deep copy of the list.
 * @TIME:2015-7-4
 * @FROM:leetcode
 * @TYPE：复杂链表/哈希表
 * @author ShaoCheng
 */
package leetcode;

import java.util.HashMap;
import java.util.Iterator;

/**思路1:遍历法，分三个步骤：
 * 		1.拷贝每一个节点，并让其指向下一个，如，1->2->3->4，拷贝之后1->1->2->2->3->4
 * 		2.处理random指针
 * 		3.分拆链表
 * 算法性能：最优的算法性能：时间复杂度O(n)，空间性能O(1)
 */
class Solution_1 { //每一个java文件中只能有一个public类
    public RandomListNode copyRandomList(RandomListNode head) {
    	if(head == null)
    		return null;
        RandomListNode node1 = head;
        RandomListNode node2 = null;
        
        //拷贝
        while(node1 != null){
        	RandomListNode tmp = node1.next; //缓存下一个节点的引用
        	node2 = new RandomListNode(node1.label); //创建一个拷贝节点
        	node2.next = tmp;
        	node1.next = node2;
        	
        	/*这部分代码有问题，只能处理random引用自身或者引用之前的节点，
        	 * 如果引用过后面的节点则在本次循环中无法处理*/
//        	if(node1.random != null) //固定random引用
//        		node2.random = node1.random.next;
        	
        	node1 = tmp; //后移
        }
        
        //真正完成random引用的复制，可能引用前面，自己，后面的节点
        node1 = head;
        while(node1 != null){
        	if(node1.random != null)
        		node1.next.random = node1.random.next;
        	node1 = node1.next.next;
        }
        
        //分离拷贝
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

/**思路2：使用哈希表。第一次遍历，创建每一节点，使用哈希表存放新旧节点的映射关系<old, new>
 * 		第二遍历，处理random指针域，借助找到old.random指针所指的节点，再查询哈希表。
 * 性能：时间复杂度O(n)， 空间复杂度O(n)。
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
			hmap.put(node1, node2); //存放新、旧节点的映射关系
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