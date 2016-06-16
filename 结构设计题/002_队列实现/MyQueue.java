package leetcode;

import java.util.Stack;

/**
 * 题目：Implement Queue using Stacks
 * Implement the following operations of a queue using stacks.
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * 		You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * 		Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * 		You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 * @author ShaoCheng
 * @version 1.0 2015-10-14
 */

/**
 * 用两个栈实现了队列
 * @author ShaoCheng
 */
class MyQueue {
	private Stack<Integer> s1 = new Stack<>();
	private Stack<Integer> s2 = new Stack<>();
	
    // Push element x to the back of queue.
    public void push(int x) {
    	s1.add(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
    	if(s1.isEmpty() && s2.empty())
    		return;
    	if(s2.isEmpty()){
	    	while(!s1.isEmpty()){
	    		s2.add(s1.peek());
	    		s1.pop();
	    	}
    	}
    	s2.pop();
    }

    // Get the front element.
    public int peek() {
    	if(s1.isEmpty() && s2.empty())
    		return -1;
    	if(s2.isEmpty()){
	    	while(!s1.isEmpty()){
	    		s2.add(s1.peek());
	    		s1.pop();
	    	}
    	}
    	return s2.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}