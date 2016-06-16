/* ����ģʽ�̰߳�ȫ��ʵ��1
 * ������̬�ڲ��ࣺ����ģʽ�����ŵ�ʵ�ַ�ʽ(��������ʽ����)
 * ��ΪJava���ƹ涨����̬�ڲ���SingletonHolderֻ����ͨ����getInstance()��������ʱ���Ż���ض���Ҳֻ����һ�Σ�����ع������̰߳�ȫ�ģ���JVM��֤����
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