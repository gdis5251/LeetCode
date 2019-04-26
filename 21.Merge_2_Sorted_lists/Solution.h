
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
                                
        ListNode *head = nullptr;
        if (l1->val <= l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }

        return head;
    }
    
};


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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *cur1 = l1;
		ListNode *cur2 = l2;
		ListNode *dummyHead = new ListNode(0);
		ListNode *curD = dummyHead;

		while (cur1 && cur2)
		{
			if (cur1->val <= cur2->val)
			{
				if (dummyHead->next == nullptr)
				{
					dummyHead->next = cur1;
					curD = dummyHead->next;

					cur1 = cur1->next;
				}
				else
				{
					curD->next = cur1;
					curD = curD->next;

					cur1 = cur1->next;
				}
			}
			else
			{
				if (dummyHead->next == nullptr)
				{
					dummyHead->next = cur2;
					curD = dummyHead->next;

					cur2 = cur2->next;
				}
				else
				{
					curD->next = cur2;
					curD = curD->next;

					cur2 = cur2->next;
				}
			}

		}

		if (cur1 == nullptr)
			curD->next = cur2;
		if (cur2 == nullptr)
			curD->next = cur1;

		ListNode *ret = dummyHead->next;

		delete dummyHead;
		dummyHead = nullptr;

		return ret;
	}
};