#include <iostream>
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return head;

		ListNode *cur = head;
		int count = 0;
		//确定链表有多少个结点
		while (cur)
		{
			cur = cur->next;
			++count;
		}
		cur = head;
		k %= count;

		ListNode *new_head = head;
		for (int i = 0; i < k; i++)
		{
			//找到倒数第二个结点
			if (!cur || !cur->next)
				break;
			while (cur->next->next != nullptr)
			{
				cur = cur->next;
			}

			ListNode *next = cur->next;
			cur->next = nullptr;
			next->next = new_head;
			new_head = next;
			cur = new_head;
		}

		return new_head;
	}
};

int main(void)
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);

	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;

	Solution b;
	ListNode *ans = b.rotateRight(&a1, 2);

	return 0;
}