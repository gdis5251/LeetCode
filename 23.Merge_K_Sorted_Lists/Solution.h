#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
