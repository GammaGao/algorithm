/* ����ģʽ�̰߳�ȫ��ʵ��4
 * ˫�ؼ�ⷽ��
 */
public class Singleton {
   private static Singleton instance = null;
 
   private Singleton() { }
 
   public static Singleton getInstance() {
      if(instance == null) { //��һ���жϣ���ֹ����Ҫ�ļ��������Ч��
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
 
//����ָ�����������⣬���Բ�����ֱ��д������������
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

//�������instanceʵ��������volatile���ξͿ����ˣ�volatile���εĻ��Ϳ���ȷ��instance = new Singleton();��Ӧ��ָ������������µĵ�������Ҳ���̰߳�ȫ�ģ�
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