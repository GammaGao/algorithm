/**@TITLE:Fraction(分数) to Recurring(循环的) Decimal(小数)(分数转无限循环小数)
 * 		Given two integers representing the numerator and denominator of a 
 * 		fraction, return the fraction in string format. If the fractional
 *  	part is repeating, enclose the repeating part in parentheses.
 *		For example,
 *		Given numerator = 1, denominator = 2, return "0.5".
 *		Given numerator = 2, denominator = 1, return "2".
 *		Given numerator = 2, denominator = 3, return "0.(6)".
 * @TIME:2015-7-3
 * @FROM:leetcode
 * @TYPE:哈希表/数学
 * @AUTHOR:PengSc
 */
package leetcode;

import java.util.HashMap;

/** 思路：如17/3(分数)， 17/3=5, 17%3=2， 由于17%3 != 3， 把2加入哈希表，再2*10%3=2，发现
 * 		2在哈希表中，说明出现无限循环。找到循环节即可。
 */
public class FractionToRecurringDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        String res = null; //java中，null是一个关键字，用来表示目前没有任何对象与该变量相关联，不可以赋给基本类型变量
        HashMap<Long, Integer> hmap = new HashMap<Long, Integer>();
        
        //整数部分， int型最小负数-2147483648转变成正数时越界，故引入long型，防止这种情况越界
        long numeratorNew = numerator, denominatorNew = denominator;
        StringBuilder builder = new StringBuilder(); //StringBuilder构建子串，单线程，效率比多线程的StringBuffer高
        if(numeratorNew < 0 && denominatorNew > 0){ //正负数处理
        	numeratorNew = 0 - numeratorNew;
        	builder.append('-');
        }
        else if(numeratorNew > 0 && denominatorNew < 0){
        	denominatorNew = 0 - denominatorNew;
        	builder.append('-');
        }
        
        //String.valuleOf()把int转成String类型
        builder.append(String.valueOf(numeratorNew / denominatorNew));
        if(numeratorNew % denominatorNew == 0){
        	res = builder.toString(); //StringBuilder中方法提取出String
        	return res;
        }
        numeratorNew %= denominatorNew;
        builder.append('.');
        int start = builder.length();
        for(int i = start; numeratorNew != 0; i++){ //java中没有while(1)，因为整数不能与boolean值转换
        	long tmp = numeratorNew*10 / denominatorNew;
        	
        	if(hmap.containsKey(numeratorNew)){ //在表中找到，说明出现循环节
        		start = hmap.get(numeratorNew);
        		builder.insert(start, '(');
        		builder.append(')');
        		res = builder.toString();
        		return res;
        	}
        	hmap.put(numeratorNew, i); //i从start开始的
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
