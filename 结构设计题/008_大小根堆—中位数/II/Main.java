package leetcode;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		/* 以下代码测试大根堆  */
//		ArrayList<Integer> a = new ArrayList<>();
//		System.out.println(a.isEmpty());
//		a.add(1);
//		a.add(10);
//		a.add(8);
//		a.add(6);
//		a.add(5);
//		MaxHeap m = new MaxHeap(a);
//		System.out.println(a);
//		System.out.println(m.heapSize);
//		System.out.println(m.heapTop);
//		m.add(100);
//		System.out.println(a);
//		System.out.println(m.heapSize);
//		System.out.println(m.heapTop);
//		
//		System.out.println(m.poll());
//		System.out.println(m.heapSize);
//		System.out.println(m.heapTop);
//		System.out.println(a);
//		System.out.println(a.isEmpty());
		
		/* 以下代码测试小根堆  */
//		ArrayList<Integer> b = new ArrayList<>();
//		b.add(16);
//		b.add(8);
//		b.add(10);
//		b.add(6);
//		b.add(5);
//		MinHeap m1 = new MinHeap(b);
//		System.out.println(b);
//		System.out.println(m1.heapSize);
//		System.out.println(m1.heapTop);
//		m1.add(1);
//		System.out.println(b);
//		System.out.println(m1.heapSize);
//		System.out.println(m1.heapTop);
		
		MedianFinder s = new MedianFinder();
		s.addNum(1);
		System.out.println(s.findMedian());
		s.addNum(2);
		System.out.println(s.findMedian());
		s.addNum(10);
		System.out.println(s.findMedian());
		s.addNum(3);
		System.out.println(s.findMedian());
		s.addNum(3);
		System.out.println(s.findMedian());
		s.addNum(10);
		System.out.println(s.findMedian());
	}
}