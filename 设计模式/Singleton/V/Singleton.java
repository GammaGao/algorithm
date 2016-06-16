/* 单例模式线程安全的实现4
 * 双重检测方案
 */
public class Singleton {
   private static Singleton instance = null;
 
   private Singleton() { }
 
   public static Singleton getInstance() {
      if(instance == null) { //第一次判断，防止不必要的加锁，提高效率
         synchronized (Singleton.class) {
            Singleton temp = instance;
            if(temp == null) {
               temp = new Singleton();
               instance = temp;
            }
         }
      }
 
      return instance;
   }
}
 
//由于指令重排序问题，所以不可以直接写成下面这样：
//public class Singleton {
//   private static Singleton instance = null;
// 
//   private Singleton(){}
// 
//   public static Singleton getInstance() {
//      if(instance == null) {
//    	  synchronized (Singleton.class) {
//    		  if(instance == null) {
//    			  instance = new Singleton();
//    		  }
//    	  }
//      }
//      return instance;
//   }
//}

//但是如果instance实例变量用volatile修饰就可以了，volatile修饰的话就可以确保instance = new Singleton();对应的指令不会重排序，如下的单例代码也是线程安全的：
//public class Singleton {
//   private static volatile Singleton instance = null;
// 
//   private Singleton() { }
// 
//   public static Singleton getInstance() {
//      if(instance == null) {
//         synchronized (Singleton.class) {
//            if(instance == null) {
//               instance = new Singleton();
//            }
//         }
//      }
// 
//      return instance;
//   }
//}