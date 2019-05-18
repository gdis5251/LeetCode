/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *cur = head->next;
        ListNode *prev = head;

        while (cur != nullptr)
        {
            if (prev->val != cur->val)
            {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
            else 
            {
                ListNode *del = cur;
                if (cur->next == nullptr)
                    prev->next = nullptr;
                cur = cur->next;
                delete del;
                del = nullptr;
            }    
        }

        return head;
    }
};

