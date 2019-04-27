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

		//��ÿ����������½��
		Node *cur = head;
		while (cur)
		{
			Node *node = new Node(cur->val, nullptr, nullptr);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}

		//��ֵ���ָ��
		cur = head;
		while (cur)
		{
			if (cur->random != nullptr)
				cur->next->random = cur->random->next;

			cur = cur->next->next;
		}

		//������
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