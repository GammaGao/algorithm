package exam;

/**��������ģʽ
 * �ѹ���Ҳ�����˳������������ʵ�ֵĹ���
 * @author ShaoCheng
 * @version 1.1 2015-12-5
 */
class Main {
	public static void main(String[] args) {
		PizzaStore factory = new NYStylePizzaStore();
		factory.create("cheese");
		factory.create("greek");
		
		PizzaStore factory2 = new ChicagoStylePizzaStore();
		factory2.create("cheese");
		factory2.create("greek");
	}
}

/********************start***************************/
/* �����ӿ� */
interface PizzaStore {
	/* �������� */
	Pizza create(String type);
}

/* ʵ��һ�����幤����ŦԼ��񹤳�  */
class NYStylePizzaStore implements PizzaStore{
	@Override
	public Pizza create(String type) {
		Pizza pizza = null;
		if(type.equals("cheese")) {
			pizza = new NYStyleCheesePizza();
		}
		else if(type.equals("greek")) {
			pizza = new NYStyleGreekPizza();
		}
		else
			return pizza;
		pizza.bake();
		pizza.cut();
		pizza.box();
		return pizza;
	}
}

/* ʵ��һ�����幤����֥�Ӹ��񹤳�  */
class ChicagoStylePizzaStore implements PizzaStore{
	@Override
	public Pizza create(String type) {
		Pizza pizza = null;
		if(type.equals("cheese")) {
			pizza = new ChicagoSytleCheesePizza();
		}
		else if(type.equals("greek")) {
			pizza = new ChicagoSytleGreekPizza();
		}
		else
			return pizza;
		pizza.bake();
		pizza.cut();
		pizza.box();
		return pizza;
	}
}
/**********************end***************************/

/********************start***************************/
/* ��Ʒ�ӿ� */
interface Pizza {
	void bake(); //�濾
	void cut(); //��Ƭ
	void box(); //װ��
}

/* �����Ʒʵ�֣�ŦԼ���Cheese */
class NYStyleCheesePizza implements Pizza {

	@Override
	public void bake() {
		System.out.println("New York Cheese Pizza baking...");
	}

	@Override
	public void cut() {
		System.out.println("New York Cheese Pizza cutting...");
	}

	@Override
	public void box() {
		System.out.println("New York Cheese Pizza boxing...");
	}
}

/* �����Ʒʵ�֣�ŦԼ���Greek */
class NYStyleGreekPizza implements Pizza {
	public void bake() {
		System.out.println("New York Greek Pizza baking...");
	}
	
	public void cut() {
		System.out.println("New York Greek Pizza cutting...");
	}

	@Override
	public void box() {
		System.out.println("New York Greek Pizza boxing...");
	}
}

/* �����Ʒʵ�֣�֥�Ӹ���Cheese */
class ChicagoSytleCheesePizza implements Pizza {

	@Override
	public void bake() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Cheese Pizza baking...");
	}

	@Override
	public void cut() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Cheese Pizza cutting...");
	}

	@Override
	public void box() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Cheese Pizza boxxing...");
	}
	
}

/* �����Ʒʵ�֣�֥�Ӹ���Greek */
class ChicagoSytleGreekPizza implements Pizza {

	@Override
	public void bake() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Greek Pizza baking...");
	}

	@Override
	public void cut() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Greek Pizza cutting...");
	}

	@Override
	public void box() {
		// TODO Auto-generated method stub
		System.out.println("Chicago Greek Pizza boxxing...");
	}
	
}
/**********************end***************************/