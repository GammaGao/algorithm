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
 * @see 自己实现的大根堆与小根堆，对堆顶元素的删除操作时间复杂度O(nlogn)，效率略低，推荐使用优先级队列
 * 思路：使用一个大根堆和一个小根堆，大根堆保存所有小于等于中位数的元素，小根堆保存所有大于等于中位数的元素
 */
//Your MedianFinder object will be instantiated and called as such:
//MedianFinder mf = new MedianFinder();
//mf.addNum(1);
//mf.findMedian();
class MedianFinder {
	private ArrayList<Integer> lowHalf;
	private ArrayList<Integer> HighHalf;
	private MaxHeap maxHeap; //大根堆，保存lowHalf
	private MinHeap minHeap; //小根堆，保存HighHalf
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
    	
    	//保持大根堆与小根堆的平衡
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

//大根堆(用数组表示（但在逻辑上树的形式），没有使用二叉树)
class MaxHeap {
	private int heapTop;
	private int heapSize;
	ArrayList<Integer> a;
	
	public MaxHeap(ArrayList<Integer> num){
		a = num;
		heapSize = a.size();
		buildMaxHeap(a);
	}
	
	//在尾部添加元素并调整，时间复杂度O(logN)
	public void add(int e) {
		a.add(e);
		heapSize++;
		buildMaxHeap(a);
	}
	
	//删除获取并堆顶元素
	public int poll() {
		if(heapSize == 0)
			return 0;
		int res = a.remove(0);
		heapSize--;
		buildMaxHeap(a);
		return res;
	}
	
	//获取堆顶元素，但不删除, 时间复杂度O(1)
	public int peek() {
		if(heapSize == 0)
			return 0;
		return heapTop;
	}
	
	//判断堆是否为空, 时间复杂度O(1)
	public boolean isEmpty() {
		return heapSize == 0;
	}
	
	//返回堆中元素的个数，时间复杂度O(1)
	public int size() {
		return heapSize;
	}
	
	//建立大根堆时间复杂度O(n)
	private void buildMaxHeap(ArrayList<Integer> a) {
		if(a.size() == 0)
			return;
		for(int i = heapSize/2; i >= 0; i--){
			maxHeapify(a, i);
		}
		heapTop = a.get(0);
	}
	
	//维持最大堆的性质
	private void maxHeapify(ArrayList<Integer> a, int rootIndex) {
		if(rootIndex >= heapSize)
			return;
		int leftChild = leftChildIndex(rootIndex);
		int rightChild = rightChildIndex(rootIndex);
		int lagest = rootIndex; //存放root, 左子节点， 右子节点中最大值的索引
		if(leftChild < heapSize && a.get(leftChild) > a.get(rootIndex)) {
			lagest = leftChild;
		}
		if(rightChild < heapSize && a.get(rightChild) > a.get(lagest)) {
			lagest = rightChild;
		}
		if(lagest != rootIndex) {
			Collections.swap(a, rootIndex, lagest); //交换root与最大值的位置
			//递归维护子树的最大堆性质，实际上如果放弃调用这个递归，依然会得到最大的堆顶元素，但会导致此时子树可能不再是大根堆
			maxHeapify(a, lagest);
		}
	}
	
	//注意rootIndex从0开始算，而不是从1开始计算
	private int leftChildIndex(int rootIndex){
		return 2*rootIndex + 1;
	}
	
	private int rightChildIndex(int rootIndex){
		return 2*rootIndex + 2;
	}
}

//小根堆(用数组表示（但在逻辑上树的形式），没有使用二叉树)
class MinHeap {
	private int heapTop;
	private int heapSize;
	ArrayList<Integer> a;
	
	public MinHeap(ArrayList<Integer> num){
		a = num;
		heapSize = a.size();
		buildMinHeap(a);
	}
	
	//在尾部添加元素并调整，时间复杂度O(logN)
	public void add(int e) {
		a.add(e);
		heapSize++;
		buildMinHeap(a);
	}
	
	//获取并删除堆顶元素
	public int poll() {
		if(heapSize == 0)
			return 0;
		int res = a.remove(0);
		heapSize--;
		buildMinHeap(a);
		return res;
	}
	
	//获取堆顶元素，但不删除
	public int peek() {
		if(heapSize == 0)
			return 0;
		return heapTop;
	}
	
	//判断堆是否为空
	public boolean isEmpty() {
		return heapSize == 0;
	}
	
	//返回堆中元素的个数
	public int size() {
		return heapSize;
	}
	
	//建立小根堆时间复杂度O(logN)
	private void buildMinHeap(ArrayList<Integer> a) {
		if(a.size() == 0)
			return;
		for(int i = heapSize/2; i >= 0; i--){
			minHeapify(a, i);
		}
		heapTop = a.get(0);
	}
	
	//维持最小堆的性质
	private void minHeapify(ArrayList<Integer> a, int rootIndex) {
		if(rootIndex >= heapSize)
			return;
		int leftChild = leftChildIndex(rootIndex);
		int rightChild = rightChildIndex(rootIndex);
		int smallest = rootIndex; //存放root, 左子节点， 右子节点中最小值的索引
		if(leftChild < heapSize && a.get(leftChild) < a.get(rootIndex)) {
			smallest = leftChild;
		}
		if(rightChild < heapSize && a.get(rightChild) < a.get(smallest)) {
			smallest = rightChild;
		}
		if(rootIndex != smallest) {
			Collections.swap(a, rootIndex, smallest); //交换root与最大值的位置
			//递归维护子树的最小堆性质，实际上如果放弃调用这个递归，依然会得到最小的堆顶元素，但会导致此时子树可能不再是小根堆
			minHeapify(a, smallest);
		}
	}
	
	//注意rootIndex从0开始算，而不是从1开始计算
	private int leftChildIndex(int rootIndex){
		return 2*rootIndex + 1;
	}
	
	private int rightChildIndex(int rootIndex){
		return 2*rootIndex + 2;
	}
}