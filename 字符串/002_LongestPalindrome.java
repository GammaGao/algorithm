package java_exam;

/**
 * @author ShaoCheng
 * 性能：时间复杂度O(n^2)
 */
public class LongestPalindrome {
    public String longestPalindrome(String s) {
        String ret = "";
        
        for (int i = 0; i < s.length(); i++) { //遍历
    		for(int j = 0; j <= i && i+j < s.length(); j++){ //第一次
    			if(s.charAt(i - j) == s.charAt(i + j)){ //按奇数对称遍历
    				if(ret.length() < 2*j + 1)
    					ret = s.substring(i-j, i+j+1);
    			}
    			else
    				break;
    		}
    		
    		for(int j = 0; j <= i && i+j+1 < s.length(); j++){ //第二次
    			if(s.charAt(i-j) == s.charAt(i+j+1)){ //按偶数对称遍历
    				if(ret.length() < 2*j + 2)
    					ret = s.substring(i-j, i+j+2);
    			}
    			else
    				break;
    		}
        }
        return ret;
    }

    public static void main(String[] args) {
        LongestPalindrome a = new LongestPalindrome();
        
        //测试用例1
        String s1 = "a";
        System.out.println(a.longestPalindrome(s1));
        
        //测试用例2
        String s2 = "abc";
        System.out.println(a.longestPalindrome(s2));
        
        //测试用例3
        String s3 = "121abcbad";
        System.out.println(a.longestPalindrome(s3));
        
        //测试用例4
        String s4 = "bb";
        System.out.println(a.longestPalindrome(s4));
        
        //测试用例5
        String s5 = "cbbc";
        System.out.println(a.longestPalindrome(s5));
    }
}