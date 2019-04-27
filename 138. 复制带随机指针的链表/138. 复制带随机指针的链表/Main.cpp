/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptr;

		//在每个结点后插入新结点
		Node *cur = head;
		while (cur)
		{
			Node *node = new Node(cur->val, nullptr, nullptr);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}

		//赋值随机指针
		cur = head;
		while (cur)
		{
			if (cur->random != nullptr)
				cur->next->random = cur->random->next;

			cur = cur->next->next;
		}

		//拆开链表
		cur = head;
		Node *ans = cur->next;

		while (cur)
		{
			Node *next = cur->next;
			if (!next)
				break;
			cur->next = next->next;
			if (next->next)
				next->next = next->next->next;

			cur = cur->next;
		}

		return ans;
	}
};