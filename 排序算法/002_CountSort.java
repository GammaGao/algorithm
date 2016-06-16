package java_exam;

/**
 * 计数排序算法：适合元素值不大，且重复较多的情况。计数排序的精髓在于通过统计次数进行排序，
 * 		相比于比较排序算法，性能更佳。当适用场景有限，比如对公司员工按年龄排序等。
 * 性能：时间复杂度仅O(n)，空间复杂度O(n)。
 * @author ShaoCheng
 * @version 1.0 2015-9-17
 */
public class Main {
	/* 非常巧妙的实现 */
	public static void countSort(int a[]){
		if(a == null)
			return;
		int max = a[0];
		for(int i = 1; i < a.length; i++){ //求当前数组最大值
			if(max < a[i])
				max = a[i];
		}
		
		int[] count = new int[max+1];
		for(int i = 0; i < count.length; i++){ //初始化
			count[i] = 0;
		}
		for(int i = 0; i < a.length; i++){ //统计a中各个元素出现的次数
			count[a[i]]++;
		}
		int k = 0;
		for(int i = 0; i <= max; i++){
			for(int j = 0; j < count[i]; j++){
				//值i在数组a中出现了count[i]次，就将a[]设置count[i]次，相当于给数组a[]排序
				a[k++] = i;
			}
		}
	}
	
	/* 按算法导论第三版实现 */
	public static int[] countSort1(int a[]){
		if(a == null)
			return null;
		int max = a[0];
		for(int i = 1; i < a.length; i++){ //求当前数组最大值
			if(max < a[i])
				max = a[i];
		}
		
		int[] count = new int[max+1];
		for(int i = 0; i < count.length; i++){ //初始化
			count[i] = 0;
		}
		for(int i = 0; i < a.length; i++){ //统计a中各个元素出现的次数
			count[a[i]]++;
		}
		for(int i = 1; i < count.length; i++){ //累计次数
			count[i] += count[i-1];
		}
		
		int[] b = new int[a.length];
		for(int i = a.length-1; i >= 0; i--){ //通过统计的次数决定元素位置 
			b[count[a[i]] - 1] = a[i]; //注意索引从0开始
			count[a[i]]--; //减一是为了防止相同元素插入同一位置
		}
		return b;
	}
	
	public static void main(String[] args){
		int[] a = new int[]{6, 7, 8, 10, 6, 7, 6, 6, 16, 10};
		int[] b = countSort1(a);
		for(int v: b)
			System.out.println(v);
	}
}
