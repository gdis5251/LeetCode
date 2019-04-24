# LeetCode.215 数组中的第K个最大元素

## 题目描述

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

**说明:**

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

## 方法一

先对这个数组进行排序(C++可以用算法包里的sort()函数进行排序)，然后返回倒数第K个元素就行。

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());//从小到大排序
        
        return nums[nums.size() - k];
    }
};
```

## 方法二

用到优先队列的方法，将所有的元素插入到优先队列中（大堆）。然后对优先队列进行出队，出k - 1个元素，返回队首元素。

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for (const auto& e : nums)
        {
            pq.push(e);
        }
        
        for (int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};
```

## 方法三

我们对方法二进行一下改进，我们没有必要把所有的元素都插入进来，我们先定义一个(小堆)优先队列，然后始终保持这个队列里有K个元素，然后我们每次只需要判断队首元素和下一个数组中的元素谁大谁小就行。如果数组中的元素大于队首元素，就先让队首元素出队，然后将数组该元素入队。遍历一遍数组后，返回队首元素即可。

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        
        for (size_t i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        
        for(size_t j = k; j < nums.size(); j++)
        {
            if (nums[j] > pq.top())
            {
                pq.pop();
                pq.push(nums[j]);
            }
        }
        
        return pq.top();
    }
};
```

