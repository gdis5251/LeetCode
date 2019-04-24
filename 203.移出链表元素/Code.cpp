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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        
        while (cur)
        {
            if (cur->val == val && prev == nullptr)
            {
                ListNode *next = cur->next;
                delete cur;
                cur = next;
                head = next;
            }
            else if (cur->val == val && prev != nullptr)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
            else if (cur->val != val)
            {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};