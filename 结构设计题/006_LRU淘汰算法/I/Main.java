package leetcode;

public class Main {
	public static void main(String[] args){
//		LRUCache sl = new LRUCache(1);
//		sl.set(5001, 1);
//		System.out.println(sl.get(5001));
//		sl.set(5002, 2);
//		System.out.println(sl.get(5001)); //被淘汰，输出-1
//		System.out.println(sl.get(5002));
		
//		LRUCache sl = new LRUCache(2);
//		sl.set(5001, 1);
//		sl.set(5002, 2);
//		System.out.println(sl.get(5001));
//		System.out.println(sl.get(5002));
//		sl.set(5003, 3);
//		System.out.println(sl.get(5001));
//		System.out.println(sl.get(5002));
//		System.out.println(sl.get(5003));
		
		LRUCacheII sl = new LRUCacheII(2);
		sl.set(2,1);
		sl.set(2,2);
		System.out.println(sl.get(2));
		sl.set(1,1);
		sl.set(4,1);
		System.out.println(sl.get(2));
		
//		LRUCache sl = new LRUCache(3);
//		sl.set(5001, 1);
//		sl.set(5002, 2);
//		sl.set(5003, 3);
//		System.out.println(sl.get(5002));
//		sl.set(5004, 4); //LRU把5001剔除出去
//		System.out.println(sl.get(5001)); //输出-1
//		System.out.println(sl.get(5002)); //名中5002
//		sl.set(5001, 1); //LRU此时把5003剔除
//		System.out.println(sl.get(5004));
	}
}
