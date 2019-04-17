#pragma once

#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
        
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());//把maxHeap里最小的元素放上去
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size())
        {
            //把minHeap的最大的元素再拿下来
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
        
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int> > maxHeap;
    std::priority_queue<int> minHeap;
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 **/
