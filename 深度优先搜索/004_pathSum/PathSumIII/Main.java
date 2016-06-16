package leetcode;

public class Main {
	public static void main(String[] args){
		Solution sl = new Solution();
		Node p0 = new Node(1);
		Node p1 = new Node(5);
		Node p2 = new Node(3);
		Node p3 = new Node(7);
		p0.left = p1;
		p0.right = p2;
		p1.left = p3;
		System.out.println(sl.sumNumbers(p0));
	}
}
