package leetcode;

/* 抽象工厂方法  */
public abstract class AbstractDuckFactory {
	public abstract Quackable createMallardDuck();
	public abstract Quackable createRedHeadDuck();
	public abstract Quackable createDuckCall();
	public abstract Quackable createRubberDuck();
}
