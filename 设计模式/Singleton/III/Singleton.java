/* ����ģʽ�̰߳�ȫ��ʵ��3
 * ��ͨ����synchronized
 * ��Ȼ������̰߳�ȫ���⣬Ч�ʵ��¡���Ϊÿ���̵߳���getInstance��Ҫ������������Ҫֻ�ڵ�һ�ε���getInstanceʱ�������뿴˫�ؼ�ⷽ��
 */
public class Singleton {
   private static Singleton instance = null;
 
   private Singleton() { }
    
   public static synchronized Singleton getInstance() {
      if(instance == null) {
         instance = new Singleton();
      }
      return instance;
   }
}