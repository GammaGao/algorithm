package leetcode;

public class Main {
	public static void main(String[] args){
//		LRUCache sl = new LRUCache(1);
//		sl.set(5001, 1);
//		System.out.println(sl.get(5001));
//		sl.set(5002, 2);
//		System.out.println(sl.get(5001)); //����̭�����-1
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
//		sl.set(5004, 4); //LRU��5001�޳���ȥ
//		System.out.println(sl.get(5001)); //���-1
//		System.out.println(sl.get(5002)); //����5002
//		sl.set(5001, 1); //LRU��ʱ��5003�޳�
//		System.out.println(sl.get(5004));
	}
}
