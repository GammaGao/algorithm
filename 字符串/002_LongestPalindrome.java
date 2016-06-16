package java_exam;

/**
 * @author ShaoCheng
 * ���ܣ�ʱ�临�Ӷ�O(n^2)
 */
public class LongestPalindrome {
    public String longestPalindrome(String s) {
        String ret = "";
        
        for (int i = 0; i < s.length(); i++) { //����
    		for(int j = 0; j <= i && i+j < s.length(); j++){ //��һ��
    			if(s.charAt(i - j) == s.charAt(i + j)){ //�������ԳƱ���
    				if(ret.length() < 2*j + 1)
    					ret = s.substring(i-j, i+j+1);
    			}
    			else
    				break;
    		}
    		
    		for(int j = 0; j <= i && i+j+1 < s.length(); j++){ //�ڶ���
    			if(s.charAt(i-j) == s.charAt(i+j+1)){ //��ż���ԳƱ���
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
        
        //��������1
        String s1 = "a";
        System.out.println(a.longestPalindrome(s1));
        
        //��������2
        String s2 = "abc";
        System.out.println(a.longestPalindrome(s2));
        
        //��������3
        String s3 = "121abcbad";
        System.out.println(a.longestPalindrome(s3));
        
        //��������4
        String s4 = "bb";
        System.out.println(a.longestPalindrome(s4));
        
        //��������5
        String s5 = "cbbc";
        System.out.println(a.longestPalindrome(s5));
    }
}