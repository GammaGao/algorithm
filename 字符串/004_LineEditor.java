import java.io.*;
import java.util.*;

/**行编辑器
 * 你知道行编辑器吗？不知道也没关系，现在我会告诉你：
 * 1.如果你收到一个'#'，那么你应该删掉一个你已经收到的字符，不包括'#';
 * 2.如果你收到一个'@'，那么你应该把你收到的一整行都删掉。(‘#’和‘@’都为不可见字符。)
 * 你明白了吗？现在轮到你去解决这个问题啦！
 * 输入
 * 第一行是一个整数T，代表有T组数据。
 * 每组数据的开始时一个字符串，字符串长度小于100，每个字符一定是('a'~'z','A'~'Z','*','!','(',')','+','@','#')中的一个
 * 输出
 * 每组数据输出一行经过行编辑器编辑过的字符串，具体可以看样例
 *
 * 样例输入
 * 3
 * whli##ilr#e(s#*s)
 * outcha@putchar(*s=#++)
 * returnWA##A!!##C
 * 样例输出
 * while(*s)
 * putchar(*s++)
 * returnAC
 *
 * @author ShaoCheng
 * @version 1.0 2015-10
 * @see acmcoder
 */
public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);

        while(cin.hasNextLine()){
            String nStr = cin.nextLine();
            int n = Integer.parseInt(nStr);

            while(n!=0){
                n--;
                String str = cin.nextLine();
                Stack<Character> stack = new Stack<Character>();

                int len = str.length();
                for(int i=0; i<len; i++){
                    if(str.charAt(i) == '@'){
                        while(!stack.empty()) stack.pop();
                    }else if(str.charAt(i) == '#'){
                        if(!stack.empty()) stack.pop();
                    }else{
                        stack.push(str.charAt(i));
                    }
                }
                StringBuilder sb = new StringBuilder();
                while(!stack.empty()){
                    sb.append(stack.pop());
                }
                System.out.println(sb.reverse().toString());
            }
        }
        cin.close();
    }
}
