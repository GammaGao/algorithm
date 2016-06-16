package leetcode;

import java.util.Stack;

/**实现一个维护最大值的栈，获取最大值的时间复杂度O(1)
 * 以下直接使用原生栈实现，当然可以使用数组或者队列模拟，看具体需求。
 * @author ShaoCheng
 * @version 1.1 2015-10-25
 */
public class MaxStack {
	//存放实际数据的栈
	private Stack<Integer> stack = new Stack<>();
	//存放数据栈的每种状态的最大值
	private Stack<Integer> maxStack = new Stack<>();
	
	public void push(int x){
		if(stack.isEmpty())
			maxStack.push(x);
		else{
			int top = maxStack.peek();
			maxStack.push(x > top ? x : top);
		}
		stack.push(x);
	}
	
	public void pop(){
		if(stack.isEmpty())
			return;
		stack.pop();
		maxStack.pop();
	}
	
	public int peek(){
		if(stack.isEmpty())
			return -1;
		return stack.peek();
	}
	
	//如果栈中为空，可以选择抛出异常行为，也可以选择返回-1
	public int max(){
		if(maxStack.isEmpty())
			return -1;
		return maxStack.peek();
	}
	
	public boolean empty(){
		return stack.isEmpty();
	}
}
