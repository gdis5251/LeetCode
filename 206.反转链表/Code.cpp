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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *ans = new ListNode(-1);
        ans->next = nullptr;
        
        while (cur)
        {
            ListNode *next = cur->next;
            
            cur->next = ans->next;
            ans->next = cur;
            
            cur = next;
        }
        
        ListNode *ret = ans->next;
        delete ans;
        ans = nullptr;
        
        return ret;
    }
};