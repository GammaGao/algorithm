package exam;

/**工厂方法模式
 * 把工厂也进行了抽象，由子类具体实现的工厂
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
/* 工厂接口 */
interface PizzaStore {
	/* 工厂方法 */
	Pizza create(String type);
}

/* 实现一个具体工厂：纽约风格工厂  */
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

/* 实现一个具体工厂：芝加哥风格工厂  */
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
/* 产品接口 */
interface Pizza {
	void bake(); //烘烤
	void cut(); //切片
	void box(); //装箱
}

/* 具体产品实现：纽约风格Cheese */
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

/* 具体产品实现：纽约风格Greek */
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

/* 具体产品实现：芝加哥风格Cheese */
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

/* 具体产品实现：芝加哥风格Greek */
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