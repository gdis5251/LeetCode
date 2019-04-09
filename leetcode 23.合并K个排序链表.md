# leetcode 23.合并K个排序链表

**题目描述：**

合并 *k* 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

**示例:**

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

**解题思路**:

你是否还记得这道题的简单版本《LeetCode 21.合并两个有序链表》。对这道题的思路就是将21延伸一下。我们使用归并排序的思想，将多个链表拆分开。最后变成两个两个链表去合并，结果就出来啦。

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        else if (lists.size() == 1)
            return lists[0];
        else if (lists.size() == 2)
            return merge2Lists(lists[0], lists[1]);
            
        //将原链表数组分成两部分
        size_t mid = lists.size() / 2;
                
        vector<ListNode*> l1;
        l1.resize(mid);
        for (size_t i = 0; i < mid; i++)
        {
            l1[i] = lists[i];
        }
                           
        vector<ListNode*> l2;
        l2.resize(lists.size() - mid);
        for(size_t i = mid; i < lists.size(); i++)
        {
            l2[i - mid] = lists[i];
        }
                           
        return merge2Lists(mergeKLists(l1), mergeKLists(l2));
    }
                  
    ListNode* merge2Lists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
                
        ListNode *head = nullptr;
        if (l1->val <= l2->val)
        {
            head = l1;
            head->next = merge2Lists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = merge2Lists(l1, l2->next);
        }
                                    
        return head;
    }
};
```

