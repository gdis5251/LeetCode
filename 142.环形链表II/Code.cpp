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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lengthA = 0;
        int lengthB = 0;
        
        while (curA)
        {
            lengthA++;
            curA = curA->next;
        }
        
        while (curB)
        {
            lengthB++;
            curB = curB->next;
        }
        
        curA = headA;
        curB = headB;
        
        if (lengthA > lengthB)
        {
            while (lengthA - lengthB)
            {
                curA = curA->next;
                lengthA--;
            }
        }
        else
        {
            while (lengthB - lengthA)
            {
                curB = curB->next;
                lengthB--;
            }
        }
        
        while (curA && curB)
        {
            if (curA == curB)
                return curA;
            
            curA = curA->next;
            curB = curB->next;
        }
        
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        int flag = 0; //标记有没有环,默认没有
        
        while (fast && slow)
        {
            slow = slow->next;
            
            fast = fast->next;
            if (fast == nullptr)
            {
                return nullptr;
            }
            fast = fast->next;
            
            if (fast == slow)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0)
            return nullptr;
        
        slow = slow->next;
        fast->next = nullptr;
        fast = head;
        
        return getIntersectionNode(slow, fast);
    }
};