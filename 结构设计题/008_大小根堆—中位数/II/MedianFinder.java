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
 * @see 1.0 �����1.0�汾��ʹ��ϵͳԭ�������ȼ����У��ö�ʵ�֣�����ԶԶѶ�Ԫ�ؽ���ɾ������ʱ�临�ӶȾ�O(logn)
 * ��̬�ҳ���λ����ʱ�临�Ӷ�O(logn)
 * ˼·��ʹ��һ������Ѻ�һ��С���ѣ�����ѱ�������С�ڵ�����λ����Ԫ�أ�С���ѱ������д��ڵ�����λ����Ԫ��
 */
public class MedianFinder {
	//���ȼ�����Ĭ���Ǵ�С�������е�
	PriorityQueue<Integer> minHeap=new PriorityQueue<Integer>(); //С����
	PriorityQueue<Integer> maxHeap=new PriorityQueue<Integer>(Collections.reverseOrder()); //�����
	// Adds a number into the data structure.
	public void addNum(int num) {
	    if(maxHeap.isEmpty() || num<=maxHeap.peek())
	    	maxHeap.offer(num);
	    else
	    	minHeap.offer(num);
	    
	    //���������ѵ�ƽ��
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