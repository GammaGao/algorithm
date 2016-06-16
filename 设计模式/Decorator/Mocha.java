package leetcode;

/* Ħ��װ���� */
public class Mocha extends CondimentDecorator {
	Beverage beverage;  //��¼��װ����
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
