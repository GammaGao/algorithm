package leetcode;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

/**题目：Given an Iterator class interface with methods: next() and hasNext(), 
 * 	design and implement a PeekingIterator that support the peek() operation -- 
 * 	it essentially peek() at the element that will be returned by the next call to next().
 *	Here is an example. Assume that the iterator is initialized to the beginning of the list:
 *	[1, 2, 3]. Call next() gets you 1, the first element in the list.
 *	Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
 *	You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
 * 
 * @author ShaoCheng
 * @version 1.0 2015-10-15
 * @TODO 尝试不使用队列来完成；尝试不针对Integer类型有效；
 * @see leetcode
 */

//Java Iterator interface reference:
//https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
public class PeekingIterator implements Iterator<Integer> {
	static Queue<Integer> q = new LinkedList<>();
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
		while(iterator.hasNext()){
			q.add(iterator.next());
		}
	}

 // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
		return q.peek();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    return q.poll();
	}

	@Override
	public boolean hasNext() {
	    return !q.isEmpty();
	}
}
