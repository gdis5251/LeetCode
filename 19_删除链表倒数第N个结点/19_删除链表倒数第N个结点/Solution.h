#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//* Definition for singly - linked list.
struct ListNode {
	int val;
	struct ListNode *next;
	
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (head == NULL)
		return NULL;

	struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	dummyHead->next = head;

	struct ListNode *p = dummyHead;
	struct ListNode *q = dummyHead;

	for (int i = 0; i < n + 1; i++)
	{
		assert(q);
		q = q->next;
	}

	while (q)
	{
		p = p->next;
		q = q->next;
	}

	struct ListNode *del = p->next;
	p->next = p->next->next;
	free(del);
	del = NULL;

	struct ListNode *ret = dummyHead->next;
	free(dummyHead);
	dummyHead = NULL;
	return ret;
}