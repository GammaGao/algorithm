/* 单例模式线程安全的实现3
 * 普通加锁synchronized
 * 虽然解决了线程安全问题，效率低下。因为每个线程调用getInstance都要加锁，我们想要只在第一次调用getInstance时加锁，请看双重检测方案
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