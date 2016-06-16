package leetcode;

/**�༭����
 * �ǳ�����Ķ�̬�滮����
 * �༭�����������ƶȷ�������ʮ����Ҫ��Ӧ�ã�DNA���ơ����ĳ�Ϯ����Ȼ���Դ���ȡ�
 * @author ShaoCheng
 * @version 1.0 2015-10-25
 */
// �ǵݹ�ʵ�֣�ʱ�临�Ӷ�O(m*n)
class Main{
	public static void main(String[] args){
		System.out.println(editDistance("sting", "cbsting"));
		System.out.println();
		System.out.println(editDistance("sailn", "failing"));
	}
	
	public static int editDistance(String s1, String s2){
		int[][] a = new int[s1.length()+1][s2.length()+1];
		for(int i = 0; i <= s1.length(); i++)
			a[i][0] = i;
		for(int j = 0; j <= s2.length(); j++)
			a[0][j] = j;
		
		for(int j = 1; j < s2.length()+1; j++){
			for(int i = 1; i < s1.length()+1; i++){
				int d = 1;
				if(s2.charAt(j-1) == s1.charAt(i-1)){
					d = 0;
				}
				int t = Math.min(a[i-1][j] + 1, //ɾ��
						a[i][j-1] + 1); //����
				a[i][j] = Math.min(a[i-1][j-1] + d, //�滻
						t);
			}
		}
		
		for(int i = 0; i <= s1.length(); i++){
			for(int j = 0; j <= s2.length(); j++)
				System.out.print(a[i][j] + " ");
			System.out.print('\n');
		}
		return a[s1.length()][s2.length()];
	}
}