package java_exam;
import java.util.Scanner;

/* 
 * 题目：海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子凭据分为五份，
 *      多了一个，这只猴子把多的一个扔入海中，拿走了一份。第二只猴子把剩下
 *      的桃子又平均分成五份，又多了一个，它同样把多的一个扔入海中，拿走了一份，
 *      第三、第四、第五只猴子都是这样做的，问海滩上原来最少有多少个桃子？
 * 扩展：假如海滩上有N（1 < N）只猴子，按上述的方式，海滩上原来最少有多少个桃子呢？
 *      如果海滩上只有一个猴子，按上述规则就变成扔一个，再分成1份，再拿走这一份，
 *      这样会显得比较奇葩。不合理情理，所以限制N>1。
 * 算法的效率并不高，从桃子总数total为1开始测试。保证后续分配是整数就是合理的。
 */
public class MonkeyDemo {
    public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt(); //输入猴子的数目
        int i, total = 1, x = 1;
        while (true) {
        	x = total;
        	for(i = 0; i < number; i++){
        		if((x-1) > 0 && (x - 1) % number == 0){ //关键在于保证是整除的关系
        			x = (x - 1)*(number-1)/(number);
        		}
        		else{
        			break;
        		}
        	}
        	if(i == number)
        		break;
        	total++;
        }
        System.out.println(total);
        scanner.close();
    }
}