package leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

/**实现LRU缓存淘汰算法
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. 
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * @author ShaoCheng
 * @version 1.0 2015-10-15
 * @TODO 其中set和get操作使用了LinkeList中的时间复杂度O(n)的remove方法。
 * 	最坏情况下，导致LRUCache的get和set的时间复杂度为O(n)。
 * @see 2.0版LRU实现 leetcode
 * 思路：哈希表存储key->value用于查询，使用LinkedList队列(注意其问题)。队列中存放vaulue。
 */
public class LRUCache {
    private int capacity; //LRU容量
    private Queue<Integer> q; //队列
    private HashMap<Integer, Integer> map; //key->value
    public LRUCache(int capacity) {
        this.capacity = capacity;
        q = new LinkedList<>();
        map = new HashMap<>();
    }
    
    public int get(int key) {
        if(map.containsKey(key)){ //命中
        	q.remove(Integer.valueOf(key));
        	q.add(key);
        	return map.get(key);
        }
        return -1;
    }
    
    public void set(int key, int value) {
        if(q.size() < capacity && !map.containsKey(key)){ //没存满、不命中
        	q.add(key);
        	map.put(key, value);
        }
        else if(q.size() <= capacity && map.containsKey(key)){ //存满或没存满、命中
        	q.remove(Integer.valueOf(key)); //时间复杂度O(n)
        	q.add(key);
        }
        else { //存满、没命中
        	int head = q.remove();
        	map.remove(head);
        	q.add(key);
        	map.put(key, value);
        }
    }
}
