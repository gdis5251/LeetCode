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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
};