package java_exam;
import java.util.Scanner;

/* 
 * ��Ŀ����̲����һ�����ӣ���ֻ�������֡���һֻ���Ӱ��������ƾ�ݷ�Ϊ��ݣ�
 *      ����һ������ֻ���ӰѶ��һ�����뺣�У�������һ�ݡ��ڶ�ֻ���Ӱ�ʣ��
 *      ��������ƽ���ֳ���ݣ��ֶ���һ������ͬ���Ѷ��һ�����뺣�У�������һ�ݣ�
 *      ���������ġ�����ֻ���Ӷ����������ģ��ʺ�̲��ԭ�������ж��ٸ����ӣ�
 * ��չ�����纣̲����N��1 < N��ֻ���ӣ��������ķ�ʽ����̲��ԭ�������ж��ٸ������أ�
 *      �����̲��ֻ��һ�����ӣ�����������ͱ����һ�����ٷֳ�1�ݣ���������һ�ݣ�
 *      �������ԵñȽ����⡣������������������N>1��
 * �㷨��Ч�ʲ����ߣ�����������totalΪ1��ʼ���ԡ���֤�����������������Ǻ���ġ�
 */
public class MonkeyDemo {
    public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt(); //������ӵ���Ŀ
        int i, total = 1, x = 1;
        while (true) {
        	x = total;
        	for(i = 0; i < number; i++){
        		if((x-1) > 0 && (x - 1) % number == 0){ //�ؼ����ڱ�֤�������Ĺ�ϵ
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