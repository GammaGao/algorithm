package leetcode;

/**ʹ������ջʵ��һ��ά�����ֵ�Ķ���
 * ʹ�õ�ջ����ά�����ֵ����ȡ���ֵʱ�临�Ӷ�Ϊ����O(1)
 * @author ShaoCheng
 * @version 1.1 2015-10-25
 */
public class MaxQueue {
	private MaxStack s1 = new MaxStack();
	private MaxStack s2 = new MaxStack();
	
	//�����
	public void push(int x){
		s1.push(x);
	}
	
	//������
	public void pop(){
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.peek());
				s1.pop();
			}
		}
		s2.pop();
	}
	
	//��ȡ���������ֵ
	public int max(){
		if(s1.empty() && s2.empty())
			return -1;
		else if(s1.empty())
			return s2.max();
		else if(s2.empty())
			return s1.max();
		int m1 = s1.max();
		int m2 = s2.max();
		return m1 > m2 ? m1 : m2;
	}
}