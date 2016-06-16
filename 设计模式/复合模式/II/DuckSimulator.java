package leetcode;

/** 使用装饰者模式统计quack叫的次数
 * 使用装饰者模式将鹅叫装饰成鸭叫
 * 使用工厂模式生产鸭子
 * @version 1.2 2015-12-15
 */
public class DuckSimulator {
	public static void main(String[] args) {
		DuckSimulator simulator = new DuckSimulator();
		AbstractDuckFactory duckFactory = new CountingDuckFactory();
		simulator.simulate(duckFactory);
	}
	
	void simulate(AbstractDuckFactory duckFactory) {
		Quackable mallardDuck = duckFactory.createMallardDuck();
		Quackable redheadDuck = duckFactory.createRedHeadDuck();
		Quackable duckCall = duckFactory.createDuckCall();
		Quackable rubberDuck = duckFactory.createRubberDuck();
		Quackable gooseDuck = new GooseAdapter(new Goose());
		
		System.out.println("\nDuck Simulator: With Abstract Factory");
		
		simulate(mallardDuck);
		simulate(redheadDuck);
		simulate(duckCall);
		simulate(rubberDuck);
		simulate(gooseDuck);
		System.out.println("The ducks quacked " + QuackCounter.getQuacks() + " times");
	}
	
	void simulate(Quackable duck) {
		duck.quack();
	}
}
