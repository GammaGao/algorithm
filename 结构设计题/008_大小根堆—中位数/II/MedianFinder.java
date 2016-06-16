package leetcode;

import java.util.Collections;
import java.util.PriorityQueue;

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
 * @version 2.0 2015-11-6
 * @see 1.0 相比于1.0版本，使用系统原生的优先级队列（用堆实现），其对对堆顶元素进行删除操作时间复杂度均O(logn)
 * 动态找出中位数，时间复杂度O(logn)
 * 思路：使用一个大根堆和一个小根堆，大根堆保存所有小于等于中位数的元素，小根堆保存所有大于等于中位数的元素
 */
public class MedianFinder {
	//优先级对列默认是从小到大排列的
	PriorityQueue<Integer> minHeap=new PriorityQueue<Integer>(); //小根堆
	PriorityQueue<Integer> maxHeap=new PriorityQueue<Integer>(Collections.reverseOrder()); //大根堆
	// Adds a number into the data structure.
	public void addNum(int num) {
	    if(maxHeap.isEmpty() || num<=maxHeap.peek())
	    	maxHeap.offer(num);
	    else
	    	minHeap.offer(num);
	    
	    //保持两个堆的平衡
	    if(maxHeap.size()>minHeap.size()+1){
	        minHeap.offer(maxHeap.poll());
	    }
	    else if(minHeap.size()>maxHeap.size()){
	        maxHeap.offer(minHeap.poll());
	    }
	}

	// Returns the median of current data stream
	public double findMedian() {
	    if(maxHeap.size() > minHeap.size())
	    	return maxHeap.peek();
	    else
	    	return (maxHeap.peek()+minHeap.peek())/2.0;
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian();