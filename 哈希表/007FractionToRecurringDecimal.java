/**@TITLE:Fraction(����) to Recurring(ѭ����) Decimal(С��)(����ת����ѭ��С��)
 * 		Given two integers representing the numerator and denominator of a 
 * 		fraction, return the fraction in string format. If the fractional
 *  	part is repeating, enclose the repeating part in parentheses.
 *		For example,
 *		Given numerator = 1, denominator = 2, return "0.5".
 *		Given numerator = 2, denominator = 1, return "2".
 *		Given numerator = 2, denominator = 3, return "0.(6)".
 * @TIME:2015-7-3
 * @FROM:leetcode
 * @TYPE:��ϣ��/��ѧ
 * @AUTHOR:PengSc
 */
package leetcode;

import java.util.HashMap;

/** ˼·����17/3(����)�� 17/3=5, 17%3=2�� ����17%3 != 3�� ��2�����ϣ����2*10%3=2������
 * 		2�ڹ�ϣ���У�˵����������ѭ�����ҵ�ѭ���ڼ��ɡ�
 */
public class FractionToRecurringDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        String res = null; //java�У�null��һ���ؼ��֣�������ʾĿǰû���κζ�����ñ���������������Ը����������ͱ���
        HashMap<Long, Integer> hmap = new HashMap<Long, Integer>();
        
        //�������֣� int����С����-2147483648ת�������ʱԽ�磬������long�ͣ���ֹ�������Խ��
        long numeratorNew = numerator, denominatorNew = denominator;
        StringBuilder builder = new StringBuilder(); //StringBuilder�����Ӵ������̣߳�Ч�ʱȶ��̵߳�StringBuffer��
        if(numeratorNew < 0 && denominatorNew > 0){ //����������
        	numeratorNew = 0 - numeratorNew;
        	builder.append('-');
        }
        else if(numeratorNew > 0 && denominatorNew < 0){
        	denominatorNew = 0 - denominatorNew;
        	builder.append('-');
        }
        
        //String.valuleOf()��intת��String����
        builder.append(String.valueOf(numeratorNew / denominatorNew));
        if(numeratorNew % denominatorNew == 0){
        	res = builder.toString(); //StringBuilder�з�����ȡ��String
        	return res;
        }
        numeratorNew %= denominatorNew;
        builder.append('.');
        int start = builder.length();
        for(int i = start; numeratorNew != 0; i++){ //java��û��while(1)����Ϊ����������booleanֵת��
        	long tmp = numeratorNew*10 / denominatorNew;
        	
        	if(hmap.containsKey(numeratorNew)){ //�ڱ����ҵ���˵������ѭ����
        		start = hmap.get(numeratorNew);
        		builder.insert(start, '(');
        		builder.append(')');
        		res = builder.toString();
        		return res;
        	}
        	hmap.put(numeratorNew, i); //i��start��ʼ��
        	builder.append(String.valueOf(tmp));
        	numeratorNew = numeratorNew*10 % denominatorNew;
        }
        res = builder.toString();
        return res;
    }
    
	public static void main(String args[]){
		FractionToRecurringDecimal sl = new FractionToRecurringDecimal();
//		String res = sl.fractionToDecimal(17, 3); //5.(6)
//		String res = sl.fractionToDecimal(2, 3); //0.(6)
//		String res = sl.fractionToDecimal(1, 2); //0.5
//		String res = sl.fractionToDecimal(2, 1); //2
//		String res = sl.fractionToDecimal(2147483647, 370000);
//		String res = sl.fractionToDecimal(-2147483648, 370000);
//		String res = sl.fractionToDecimal(-2147483648, -370000); //5804.0098(594)
		String res = sl.fractionToDecimal(2147483647, -370000); //-5804.0098(567)

		System.out.println(res);
	}
}
