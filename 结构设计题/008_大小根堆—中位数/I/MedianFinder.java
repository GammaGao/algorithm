package leetcode;

import java.util.*;


/**Find Median from Data Stream
 * Median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value. So the median is the mean of the two middle value.
 * Examples: 
 * 	[2,3,4] , the median is 3
 * 	[2,3], the median is (2 + 3) / 2 = 2.5
 * 	Design a data structure that supports the following two operations:
 * 	void addNum(int num) - Add a integer number from the data stream to the data structure.
 * 	double findMedian() - Return the median of all elements so far.
 * 	For example:
 *	add(1)
 *	add(2)
 * 	findMedian() -> 1.5
 *	add(3) 
 *	findMedian() -> 2
 *
 * @author ShaoCheng
 * @version 1.0 2015-11-5
 * @see �Լ�ʵ�ֵĴ������С���ѣ��ԶѶ�Ԫ�ص�ɾ������ʱ�临�Ӷ�O(nlogn)��Ч���Եͣ��Ƽ�ʹ�����ȼ�����
 * ˼·��ʹ��һ������Ѻ�һ��С���ѣ�����ѱ�������С�ڵ�����λ����Ԫ�أ�С���ѱ������д��ڵ�����λ����Ԫ��
 */
//Your MedianFinder object will be instantiated and called as such:
//MedianFinder mf = new MedianFinder();
//mf.addNum(1);
//mf.findMedian();
class MedianFinder {
	private ArrayList<Integer> lowHalf;
	private ArrayList<Integer> HighHalf;
	private MaxHeap maxHeap; //����ѣ�����lowHalf
	private MinHeap minHeap; //С���ѣ�����HighHalf
	private double median;
	
	public MedianFinder() {
		lowHalf = new ArrayList<>();
		HighHalf = new ArrayList<>();
		maxHeap = new MaxHeap(lowHalf);
		minHeap = new MinHeap(HighHalf);
	}
	
    // Adds a number into the data structure.
    public void addNum(int num) {
    	if(maxHeap.isEmpty() || maxHeap.peek() >= num) {
    		maxHeap.add(num);
    	}
    	else
    		minHeap.add(num);
    	
    	//���ִ������С���ѵ�ƽ��
    	if(maxHeap.size() - minHeap.size() > 1) {
    		minHeap.add(maxHeap.poll());
    	}
    	if(maxHeap.size() - minHeap.size() < -1) {
    		maxHeap.add(minHeap.poll());
    	}
    }

    // Returns the median of current data stream
    public double findMedian() {
    	if(maxHeap.size() == minHeap.size()) {
    		median = (maxHeap.peek() + minHeap.peek())/2.0;
    	}
    	else if(maxHeap.size() > minHeap.size())
    		median = maxHeap.peek();
    	else
    		median = minHeap.peek();
    	return median;
    }
};

//�����(�������ʾ�������߼���������ʽ����û��ʹ�ö�����)
class MaxHeap {
	private int heapTop;
	private int heapSize;
	ArrayList<Integer> a;
	
	public MaxHeap(ArrayList<Integer> num){
		a = num;
		heapSize = a.size();
		buildMaxHeap(a);
	}
	
	//��β�����Ԫ�ز�������ʱ�临�Ӷ�O(logN)
	public void add(int e) {
		a.add(e);
		heapSize++;
		buildMaxHeap(a);
	}
	
	//ɾ����ȡ���Ѷ�Ԫ��
	public int poll() {
		if(heapSize == 0)
			return 0;
		int res = a.remove(0);
		heapSize--;
		buildMaxHeap(a);
		return res;
	}
	
	//��ȡ�Ѷ�Ԫ�أ�����ɾ��, ʱ�临�Ӷ�O(1)
	public int peek() {
		if(heapSize == 0)
			return 0;
		return heapTop;
	}
	
	//�ж϶��Ƿ�Ϊ��, ʱ�临�Ӷ�O(1)
	public boolean isEmpty() {
		return heapSize == 0;
	}
	
	//���ض���Ԫ�صĸ�����ʱ�临�Ӷ�O(1)
	public int size() {
		return heapSize;
	}
	
	//���������ʱ�临�Ӷ�O(n)
	private void buildMaxHeap(ArrayList<Integer> a) {
		if(a.size() == 0)
			return;
		for(int i = heapSize/2; i >= 0; i--){
			maxHeapify(a, i);
		}
		heapTop = a.get(0);
	}
	
	//ά�����ѵ�����
	private void maxHeapify(ArrayList<Integer> a, int rootIndex) {
		if(rootIndex >= heapSize)
			return;
		int leftChild = leftChildIndex(rootIndex);
		int rightChild = rightChildIndex(rootIndex);
		int lagest = rootIndex; //���root, ���ӽڵ㣬 ���ӽڵ������ֵ������
		if(leftChild < heapSize && a.get(leftChild) > a.get(rootIndex)) {
			lagest = leftChild;
		}
		if(rightChild < heapSize && a.get(rightChild) > a.get(lagest)) {
			lagest = rightChild;
		}
		if(lagest != rootIndex) {
			Collections.swap(a, rootIndex, lagest); //����root�����ֵ��λ��
			//�ݹ�ά���������������ʣ�ʵ�������������������ݹ飬��Ȼ��õ����ĶѶ�Ԫ�أ����ᵼ�´�ʱ�������ܲ����Ǵ����
			maxHeapify(a, lagest);
		}
	}
	
	//ע��rootIndex��0��ʼ�㣬�����Ǵ�1��ʼ����
	private int leftChildIndex(int rootIndex){
		return 2*rootIndex + 1;
	}
	
	private int rightChildIndex(int rootIndex){
		return 2*rootIndex + 2;
	}
}

//С����(�������ʾ�������߼���������ʽ����û��ʹ�ö�����)
class MinHeap {
	private int heapTop;
	private int heapSize;
	ArrayList<Integer> a;
	
	public MinHeap(ArrayList<Integer> num){
		a = num;
		heapSize = a.size();
		buildMinHeap(a);
	}
	
	//��β�����Ԫ�ز�������ʱ�临�Ӷ�O(logN)
	public void add(int e) {
		a.add(e);
		heapSize++;
		buildMinHeap(a);
	}
	
	//��ȡ��ɾ���Ѷ�Ԫ��
	public int poll() {
		if(heapSize == 0)
			return 0;
		int res = a.remove(0);
		heapSize--;
		buildMinHeap(a);
		return res;
	}
	
	//��ȡ�Ѷ�Ԫ�أ�����ɾ��
	public int peek() {
		if(heapSize == 0)
			return 0;
		return heapTop;
	}
	
	//�ж϶��Ƿ�Ϊ��
	public boolean isEmpty() {
		return heapSize == 0;
	}
	
	//���ض���Ԫ�صĸ���
	public int size() {
		return heapSize;
	}
	
	//����С����ʱ�临�Ӷ�O(logN)
	private void buildMinHeap(ArrayList<Integer> a) {
		if(a.size() == 0)
			return;
		for(int i = heapSize/2; i >= 0; i--){
			minHeapify(a, i);
		}
		heapTop = a.get(0);
	}
	
	//ά����С�ѵ�����
	private void minHeapify(ArrayList<Integer> a, int rootIndex) {
		if(rootIndex >= heapSize)
			return;
		int leftChild = leftChildIndex(rootIndex);
		int rightChild = rightChildIndex(rootIndex);
		int smallest = rootIndex; //���root, ���ӽڵ㣬 ���ӽڵ�����Сֵ������
		if(leftChild < heapSize && a.get(leftChild) < a.get(rootIndex)) {
			smallest = leftChild;
		}
		if(rightChild < heapSize && a.get(rightChild) < a.get(smallest)) {
			smallest = rightChild;
		}
		if(rootIndex != smallest) {
			Collections.swap(a, rootIndex, smallest); //����root�����ֵ��λ��
			//�ݹ�ά����������С�����ʣ�ʵ�������������������ݹ飬��Ȼ��õ���С�ĶѶ�Ԫ�أ����ᵼ�´�ʱ�������ܲ�����С����
			minHeapify(a, smallest);
		}
	}
	
	//ע��rootIndex��0��ʼ�㣬�����Ǵ�1��ʼ����
	private int leftChildIndex(int rootIndex){
		return 2*rootIndex + 1;
	}
	
	private int rightChildIndex(int rootIndex){
		return 2*rootIndex + 2;
	}
}