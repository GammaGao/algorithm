package leetcode;

public class Main {
	public static void main(String[] args){
		//���ֵջ����
//		MaxStack s = new MaxStack();
//		s.push(3);
//		s.push(6);
//		s.push(7);
//		s.push(4);
//		System.out.println(s.max());
//		s.pop();
//		System.out.println(s.max());
//		s.pop();
//		System.out.println(s.max());
		
		//�������ֵ����1�� ע�Ͳ��ֱ�ʾ������Ԫ��
		MaxQueue q = new MaxQueue();
		q.push(3); //3
		q.push(7); //7, 3
		System.out.println(q.max()); //7
		q.push(6);//6, 7, 3
		q.push(5);//5, 6, 7, 3
		System.out.println(q.max());//7
		q.pop();//5, 6, 7
		q.pop();//5, 6
		q.pop();//5
		System.out.println(q.max());//5
		q.push(10);//10, 5
		System.out.println(q.max());//10
		
		//�������ֵ����2
		q.push(10); //10
		q.push(8);// 8, 10
		q.pop(); //8
		q.push(100); //100, 8
		System.out.println(q.max()); //100
		q.pop(); //100
		System.out.println(q.max()); //100
	}
}
