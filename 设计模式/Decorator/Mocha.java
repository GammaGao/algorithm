package leetcode;

/* 摩卡装饰者 */
public class Mocha extends CondimentDecorator {
	Beverage beverage;  //记录被装饰者
	public Mocha(Beverage beverage) {
		this.beverage = beverage;
	}
	
	@Override
	public String getDescription() {
		return beverage.getDescription() + ", Mocha";
	}
	
	@Override
	public double cost() {
		return .20 + beverage.cost();
	}
}
