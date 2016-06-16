package leetcode;

import java.util.ArrayList;
import java.util.Iterator;

public class Main {
	public static void main(String[] args){
		ArrayList<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		Iterator<Integer> itor = a.iterator();
		PeekingIterator p = new PeekingIterator(itor);
		System.out.println(p.next());
		System.out.println(p.peek());
		System.out.println(p.next());
	}
}
