package leetcode;

import java.util.Stack;

/**ʵ��һ��ά�����ֵ��ջ����ȡ���ֵ��ʱ�临�Ӷ�O(1)
 * ����ֱ��ʹ��ԭ��ջʵ�֣���Ȼ����ʹ��������߶���ģ�⣬����������
 * @author ShaoCheng
 * @version 1.1 2015-10-25
 */
public class MaxStack {
	//���ʵ�����ݵ�ջ
	private Stack<Integer> stack = new Stack<>();
	//�������ջ��ÿ��״̬�����ֵ
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
	
	//���ջ��Ϊ�գ�����ѡ���׳��쳣��Ϊ��Ҳ����ѡ�񷵻�-1
	public int max(){
		if(maxStack.isEmpty())
			return -1;
		return maxStack.peek();
	}
	
	public boolean empty(){
		return stack.isEmpty();
	}
}
