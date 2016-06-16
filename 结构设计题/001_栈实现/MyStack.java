package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**题目：Implement the following operations of a stack using queues.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 *		You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 *		Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 *		You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

/**
 * 实现数据结构栈
 * @author ShaoCheng
 * @version 1.0 2015-10-14
 * @see leetcode
 */
public class MyStack {
	private Queue<Integer> q1 = new LinkedList<>();
	private Queue<Integer> q2 = new LinkedList<>();
	private Integer topE; //栈顶元素
	
    // Push element x onto stack.
    public void push(int x) {
        q1.add(x);
        topE = x;
    }

    // Removes the element on top of the stack.
    public void pop() {
        if(q1.isEmpty() && q2.isEmpty())
        	return;
        if(q1.isEmpty()){ //保证q1始终不为空队列
        	Queue<Integer> tmp = q1;
        	q1 = q2;
        	q2 = tmp;
        }
        if(q1.size() == 1){
        	topE = null;
        	q1.poll();
        }
        else {
            while(q1.size() > 1){ //把除最后一个元素外的其他元素均移到另一个队列中
            	if(q1.size() == 2)
            		topE = q1.peek(); //保存好新的栈顶元素
            	q2.offer(q1.peek());
            	q1.poll();
            }
            q1.poll();
        }
    }

    // Get the top element.
    public int top() {
        return topE;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
}