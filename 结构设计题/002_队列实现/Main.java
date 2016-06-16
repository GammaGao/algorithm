package leetcode;

public class Main {
	public static void main(String[] args){
		MyQueue q = new MyQueue();
		
		System.out.println(q.empty());
		
		q.push(1);
		System.out.println(q.peek());
		System.out.println(q.empty());
		
		q.push(2);
		System.out.println(q.peek());
		System.out.println(q.empty());
		
		q.pop();
		System.out.println(q.peek());
		System.out.println(q.empty());
		
		q.pop();
		System.out.println(q.peek());
		System.out.println(q.empty());
		
		q.push(1);
		q.push(2);
		System.out.println(q.peek());
		q.push(3);
		System.out.println(q.peek());
	}
}
