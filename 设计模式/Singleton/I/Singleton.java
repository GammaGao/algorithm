/* 单例模式线程安全的实现1
 * 借助静态内部类：单例模式最优雅的实现方式(属于懒汉式单例)
 * 因为Java机制规定，静态内部类SingletonHolder只有在通过在getInstance()方法调用时，才会加载而且也只加载一次，其加载过程是线程安全的（由JVM保证）。
 */
public class Singleton {
	private Singleton(){}
	private static class SingletonHolder{
		private final static Singleton instance = new Singleton();
	}
	public static Singleton getInstance(){
		return SingletonHolder.instance;
	}
}