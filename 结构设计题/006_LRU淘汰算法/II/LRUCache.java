package leetcode;

import java.util.HashMap;

/**ʵ��LRU��̭�㷨II
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * @author ShaoCheng
 * @version 2.0 2015-10-15
 * @see �����LRU�汾1.0 �㷨Ч����ߣ�set/get()ʱ�临�ӶȾ�ΪO(1)
 * ˼·����ϣ��洢key->LRU�ڵ�ʵ�����в�ѯ�� ˫������ʵ�ֶ��й��ܣ�LinkedList�޷���������
 */

/* ����ڵ㣬����˫������ */
class CacheNode{
	int key;
	int val;
	CacheNode pre;
	CacheNode next;
	public CacheNode(int key, int val) {
		this.key = key;
		this.val = val;
	}
}

public class LRUCacheII {
    private HashMap<Integer, CacheNode> map; //key->�ڵ�
    private CacheNode head; //ͷ�ڵ�
    private CacheNode tail; //β�ڵ�
    private int capacity; //LRU����
    private int size; //��ǰ˫������Ԫ�ظ���
    public LRUCacheII(int capacity) {
        map = new HashMap<>();
        this.capacity = capacity;
    }
    
    /**����keyֵ��ѯLRU����
     * @param key
     * @return �������е�ֵ������-1��
     */
    public int get(int key) {
       int val = map.containsKey(key) ? map.get(key).val : -1;
       if(map.containsKey(key)){ //����
    	   moveTail(map.get(key));
       }
       return val;
    }
    
    public void set(int key, int value) {
        if(map.containsKey(key)){ //���У�valueֵ���ܲ�ͬ�����뱻�滻������
        	CacheNode node = map.get(key);
        	node.val = value;
        	moveTail(map.get(key));
        	return;
        }
        else if(size < capacity){ //δ���С�����δ��
        	CacheNode node = new CacheNode(key, value); 
        	map.put(key, node);
        	addTail(node);
        	size++;
        }
        else { //δ���С���������
        	map.remove(head.key); //ɾ��ͷ�ڵ�����ӳ��
        	removeHead();
        	CacheNode node = new CacheNode(key, value);
        	map.put(key, node);
        	addTail(node);
        }
    }
    
    //��node�ڵ��ƶ�������β��
    private void moveTail(CacheNode node){
    	if(node.pre == null && node.next == null) //���ڵ㣨Ҳ��ͷ��
    		return;
    	else if(node.pre == null && node.next != null){ //Ϊͷ�ڵ��ҽڵ���>2
    		head = node.next;
    		head.pre = null;
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    	else if(node.pre != null && node.next != null){ //Ϊ�м�ڵ�
    		CacheNode pre = node.pre;
    		CacheNode next = node.next;
    		pre.next = node.next;
    		next.pre = pre;
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    	else { //���ڵ�
    		return;
    	}
    }
    
    //ɾ��˫������ͷ�ڵ�
    private void removeHead(){
    	if(head == null)
    		;
    	else if(head.next == null){ //���ڵ�
    		head = null;
    	}
    	else{ //�ڵ���>2
    		CacheNode p = head;
    		head = head.next;
    		p.pre = null;
    		p.next = null;
    		head.pre = null;
    	}
    }
    
    //��β����ӽڵ�
    private void addTail(CacheNode node){
    	if(tail == null){ //��һ�δ���
    		head = tail = node;
    	}
    	else{ //��ӵ�β
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    }
}