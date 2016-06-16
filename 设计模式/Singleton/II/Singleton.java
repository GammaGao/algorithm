/* 单例模式线程安全的实现2
 * 饿汉式单例
 */
public class Singleton {
   private final static Singleton INSTANCE = new Singleton();
 
   private Singleton() { }
 
   public static Singleton getInstance() {
      return INSTANCE;
   }
}