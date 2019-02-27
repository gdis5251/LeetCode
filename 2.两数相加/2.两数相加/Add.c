struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//两个链表都为空或某一个链表为空的情况
	if (l1 == NULL && l2 == NULL)
		return NULL;

	struct ListNode *newHead = NULL;
	struct ListNode *curN = NULL;
	struct ListNode *prev = NULL;
	struct ListNode *cur1 = l1;
	struct ListNode *cur2 = l2;
	int carried = 0;    //表示是否要进位的标志

	while (cur1 != NULL && cur2 != NULL)
	{
		curN = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!curN)
			exit(EXIT_FAILURE);

		curN->next = NULL;

		int res = cur1->val + cur2->val;
		if (res >= 10)//如果两个值相加大于10
		{
			if (carried == 1)//有进位就给结果模10加1
			{
				curN->val = res % 10 + 1;
			}
			else
			{
				curN->val = res % 10;
			}
			carried = 1;
		}
		else
		{
			if (carried == 1)
			{
				curN->val = res + 1;
				carried = 0;
			}
			else
			{
				curN->val = res;
			}
		}

		if (curN->val >= 10)
		{
			curN->val %= 10;
			carried = 1;
		}

		if (newHead == NULL)
		{
			newHead = curN;
			prev = curN;
			curN = curN->next;
		}
		else
		{
			prev->next = curN;
			prev = curN;
			curN = curN->next;
		}

		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	if (cur1 == NULL && cur2 != NULL)
	{
		struct ListNode *cur2_c = cur2;
		while (cur2_c)
		{
			if (carried == 1)
			{
				cur2_c->val += 1;
				carried = 0;
			}
			else
			{
				prev->next = cur2_c;
				break;
			}

			if (cur2_c->val >= 10)
			{
				carried = 1;
				cur2_c->val %= 10;
			}

			prev->next = cur2_c;
			prev = cur2_c;
			cur2_c = cur2_c->next;

		}


	}
	else if (cur1 != NULL && cur2 == NULL)
	{
		struct ListNode *cur1_c = cur1;
		while (cur1_c)
		{
			if (carried == 1)
			{
				cur1_c->val += 1;
				carried = 0;
			}
			else
			{
				prev->next = cur1_c;
				break;
			}

			if (cur1_c->val >= 10)
			{
				carried = 1;
				cur1_c->val %= 10;
			}

			prev->next = cur1_c;
			prev = cur1_c;
			cur1_c = cur1_c->next;

		}
	}

	if (carried == 1)
	{
		curN = (struct ListNode *)malloc(sizeof(struct ListNode));
		curN->val = 1;
		curN->next = NULL;
		prev->next = curN;
	}

	return newHead;
}