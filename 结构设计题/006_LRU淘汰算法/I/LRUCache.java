package leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

/**ʵ��LRU������̭�㷨
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. 
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * @author ShaoCheng
 * @version 1.0 2015-10-15
 * @TODO ����set��get����ʹ����LinkeList�е�ʱ�临�Ӷ�O(n)��remove������
 * 	�����£�����LRUCache��get��set��ʱ�临�Ӷ�ΪO(n)��
 * @see 2.0��LRUʵ�� leetcode
 * ˼·����ϣ��洢key->value���ڲ�ѯ��ʹ��LinkedList����(ע��������)�������д��vaulue��
 */
public class LRUCache {
    private int capacity; //LRU����
    private Queue<Integer> q; //����
    private HashMap<Integer, Integer> map; //key->value
    public LRUCache(int capacity) {
        this.capacity = capacity;
        q = new LinkedList<>();
        map = new HashMap<>();
    }
    
    public int get(int key) {
        if(map.containsKey(key)){ //����
        	q.remove(Integer.valueOf(key));
        	q.add(key);
        	return map.get(key);
        }
        return -1;
    }
    
    public void set(int key, int value) {
        if(q.size() < capacity && !map.containsKey(key)){ //û������������
        	q.add(key);
        	map.put(key, value);
        }
        else if(q.size() <= capacity && map.containsKey(key)){ //������û����������
        	q.remove(Integer.valueOf(key)); //ʱ�临�Ӷ�O(n)
        	q.add(key);
        }
        else { //������û����
        	int head = q.remove();
        	map.remove(head);
        	q.add(key);
        	map.put(key, value);
        }
    }
}
