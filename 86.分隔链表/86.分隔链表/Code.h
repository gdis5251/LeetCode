/*
  Definition for singly-linked list.
  */
#include <stdlib.h>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 //�ҵ�����
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
			return NULL;

		ListNode *dummyList1 = NULL;//������¼��xС�Ľ��
		ListNode *dummyList2 = NULL;//������¼���ڵ���x�Ľ��
		ListNode *cur = head;
		ListNode *mark = NULL;
		ListNode *ret = NULL;


		//������𿪣�С��x�Ľ����ʱ���뵽dummyHead1��
		//���ڵ���x�Ľ����ʱ���뵽dummyHead2��
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

//�ٷ�����
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