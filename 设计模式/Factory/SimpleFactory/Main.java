package exam;

/**简单工厂模式
 * 单工厂模式就是由一个工厂类根据传入的参数决定创建哪一种的产品类。
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
	/**创建pizza
	 * @param type 类型参数，决定创建哪种pizza
	 * @return 创建的实例引用
	 * TODO 如果有新的pizza类型，在此代码中加入
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
	void bake(); //烘烤
	void cut(); //切片
	void box(); //装箱
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