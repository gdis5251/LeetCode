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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode *curOdd = head;
        ListNode *evenHead = head->next;
        ListNode *curEven = evenHead;
        
        while (curOdd && curEven)
        {
            if (curEven->next == nullptr)
                break;
            
            curOdd->next = curEven->next;
            curOdd = curOdd->next;
            
            curEven->next = curOdd->next;
            curEven = curEven->next;
        }
        curOdd->next = evenHead;
        
        return head;
    }
};
