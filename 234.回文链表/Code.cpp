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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        
        std::stack<int> s;
        ListNode *cur = head;
        int count = 0;
        
        while (cur)
        {
            count++;
            cur = cur->next;
        }
        cur = head;
        
        for (int i = 0; i < count / 2 && cur; i++)
        {
            s.push(cur->val);
            cur = cur->next;
        }
        if (count & 1)
            cur = cur->next;
        
        while (cur)
        {
            if (s.top() == cur->val)
            {
                s.pop();
                cur = cur->next;
            }
            else 
                break;
        }
        
        if (s.empty())
            return true;
        
        return false;
    }
};