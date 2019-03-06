/*
  Definition for singly-linked list.
  */
#include <stdlib.h>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 //我的做法
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
			return NULL;

		ListNode *dummyList1 = NULL;//用来记录比x小的结点
		ListNode *dummyList2 = NULL;//用来记录大于等于x的结点
		ListNode *cur = head;
		ListNode *mark = NULL;
		ListNode *ret = NULL;


		//将链表拆开，小于x的结点暂时接入到dummyHead1中
		//大于等于x的结点暂时接入到dummyHead2中
		while (cur)
		{
			if (cur->val < x)
			{
				if (!dummyList1)
				{
					ret = cur;
					dummyList1 = cur;
				}
				else
				{
					dummyList1->next = cur;
					dummyList1 = cur;
				}

				cur = cur->next;
			}
			else
			{
				if (!dummyList2)
				{
					mark = cur;
					dummyList2 = cur;
				}
				else
				{
					dummyList2->next = cur;
					dummyList2 = cur;
				}

				cur = cur->next;
			}
		}

		if (!ret && dummyList2)
		{
			dummyList2->next = NULL;
			return mark;
		}
		else if (dummyList1 && !dummyList2)
		{
			dummyList1->next = dummyList2;
			return ret;
		}
		else if (dummyList1 && dummyList2)
		{
			dummyList1->next = mark;
			dummyList2->next = NULL;
		}
		return ret;

	}
};

//官方做法
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
	ListNode* partition(ListNode* head, int x) {
		ListNode *dummyHead1 = new ListNode(-1);
		ListNode *dummyHead2 = new ListNode(-1);
		ListNode *prev1 = dummyHead1;
		ListNode *prev2 = dummyHead2;

		for (ListNode *cur = head; cur != NULL;)
		{
			if (cur->val < x)
			{
				prev1->next = cur;
				cur = cur->next;
				prev1 = prev1->next;
				prev1->next = NULL;
			}
			else
			{
				prev2->next = cur;
				cur = cur->next;
				prev2 = prev2->next;
				prev2->next = NULL;
			}
		}

		prev1->next = dummyHead2->next;
		ListNode *ret = dummyHead1->next;

		delete dummyHead1;
		delete dummyHead2;

		return ret;
	}
};