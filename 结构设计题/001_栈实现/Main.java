package leetcode;

public class Main {
	public static void main(String[] args){
		MyStack s = new MyStack();
		System.out.println(s.empty());
		
		s.push(1);
		s.push(2);
		System.out.println(s.top());
		System.out.println(s.empty());
		
		s.pop();
		System.out.println(s.top());
		System.out.println(s.empty());
		
		s.pop();
		//System.out.println(s.top()); //注意栈为空时，做top操作时会产生异常
		System.out.println(s.empty());
	}
}
