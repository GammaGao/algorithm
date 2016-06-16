package leetcode;

import java.util.HashMap;

/**实现LRU淘汰算法II
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * @author ShaoCheng
 * @version 2.0 2015-10-15
 * @see 相比于LRU版本1.0 算法效率提高，set/get()时间复杂度均为O(1)
 * 思路：哈希表存储key->LRU节点实现命中查询， 双向链表实现队列功能，LinkedList无法满足需求。
 */

/* 缓存节点，够成双向链表 */
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
    private HashMap<Integer, CacheNode> map; //key->节点
    private CacheNode head; //头节点
    private CacheNode tail; //尾节点
    private int capacity; //LRU容量
    private int size; //当前双向链表元素个数
    public LRUCacheII(int capacity) {
        map = new HashMap<>();
        this.capacity = capacity;
    }
    
    /**根据key值查询LRU缓存
     * @param key
     * @return 返回命中的值，否则-1。
     */
    public int get(int key) {
       int val = map.containsKey(key) ? map.get(key).val : -1;
       if(map.containsKey(key)){ //命中
    	   moveTail(map.get(key));
       }
       return val;
    }
    
    public void set(int key, int value) {
        if(map.containsKey(key)){ //命中，value值可能不同，必须被替换成最新
        	CacheNode node = map.get(key);
        	node.val = value;
        	moveTail(map.get(key));
        	return;
        }
        else if(size < capacity){ //未命中、容量未满
        	CacheNode node = new CacheNode(key, value); 
        	map.put(key, node);
        	addTail(node);
        	size++;
        }
        else { //未命中、容量已满
        	map.remove(head.key); //删除头节点索引映射
        	removeHead();
        	CacheNode node = new CacheNode(key, value);
        	map.put(key, node);
        	addTail(node);
        }
    }
    
    //将node节点移动到链表尾部
    private void moveTail(CacheNode node){
    	if(node.pre == null && node.next == null) //单节点（也是头）
    		return;
    	else if(node.pre == null && node.next != null){ //为头节点且节点数>2
    		head = node.next;
    		head.pre = null;
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    	else if(node.pre != null && node.next != null){ //为中间节点
    		CacheNode pre = node.pre;
    		CacheNode next = node.next;
    		pre.next = node.next;
    		next.pre = pre;
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    	else { //最后节点
    		return;
    	}
    }
    
    //删除双向链表头节点
    private void removeHead(){
    	if(head == null)
    		;
    	else if(head.next == null){ //单节点
    		head = null;
    	}
    	else{ //节点数>2
    		CacheNode p = head;
    		head = head.next;
    		p.pre = null;
    		p.next = null;
    		head.pre = null;
    	}
    }
    
    //在尾部添加节点
    private void addTail(CacheNode node){
    	if(tail == null){ //第一次创建
    		head = tail = node;
    	}
    	else{ //添加到尾
    		tail.next = node;
    		node.pre = tail;
    		node.next = null;
    		tail = node;
    	}
    }
}