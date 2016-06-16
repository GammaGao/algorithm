package exam;

/**�򵥹���ģʽ
 * ������ģʽ������һ����������ݴ���Ĳ�������������һ�ֵĲ�Ʒ�ࡣ
 * @author ShaoCheng
 * @version 1.0 2015-12-5
 */
class Main {
	public static void main(String[] args) {
		Pizza pizza = SimpleFactory.create("cheese");
		SimpleFactory.create("greek");
	}
}

class SimpleFactory {
	/**����pizza
	 * @param type ���Ͳ�����������������pizza
	 * @return ������ʵ������
	 * TODO ������µ�pizza���ͣ��ڴ˴����м���
	 */
	public static Pizza create(String type) {
		Pizza pizza = null;
		if(type.equals("cheese")) {
			pizza = new CheesePizza();
		}
		else if(type.equals("greek")) {
			pizza = new GreekPizza();
		}
		else 
			return pizza;
		pizza.bake();
		pizza.cut();
		pizza.box();
		return pizza;
	}
}

interface Pizza {
	void bake(); //�濾
	void cut(); //��Ƭ
	void box(); //װ��
}

/* cheese pizza */
class CheesePizza implements Pizza {

	@Override
	public void bake() {
		// TODO Auto-generated method stub
		System.out.println("Cheese Pizza baking...");
	}

	@Override
	public void cut() {
		// TODO Auto-generated method stub
		System.out.println("Cheese Pizza cutting...");
	}

	@Override
	public void box() {
		// TODO Auto-generated method stub
		System.out.println("Cheese Pizza boxing...");
	}
}

class GreekPizza implements Pizza {
	public void bake() {
		System.out.println("Greek Pizza baking...");
	}
	
	public void cut() {
		System.out.println("Greek Pizza cutting...");
	}

	@Override
	public void box() {
		// TODO Auto-generated method stub
		System.out.println("Greek Pizza boxing...");
	}
}