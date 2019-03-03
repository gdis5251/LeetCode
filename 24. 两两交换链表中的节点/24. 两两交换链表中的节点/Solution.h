/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL)
		return NULL;

	struct ListNode *ret = head->next;

	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	assert(p);

	p->next = head;
	p->val = 0;

	struct ListNode *node1 = head;
	struct ListNode *node2 = head->next;
	if (!node2)   //只有一个结点的情况
		return head;

	struct ListNode *next = node2->next;

	while (node1 && node2)
	{
		p->next = node2;
		node1->next = next;
		node2->next = node1;

		p = node1;
		node1 = next;
		if (!next)
			break;
		node2 = next->next;
		if (!node2)
			break;
		next = node2->next;

	}


	return ret;
}