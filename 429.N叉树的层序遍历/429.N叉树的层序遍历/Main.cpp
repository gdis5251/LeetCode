#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		else
		{
			deque<Node*> que;
			que.push_back(root);
			while (!que.empty())
			{
				auto size = que.size();
				vector<int> a;
				for (deque<Node*>::size_type i = 0; i < size; i++)
				{
					auto temp = que[0];
					que.pop_front();
					a.push_back(temp->val);
					if (!(temp->children).empty())
					{
						for (auto elem : temp->children)
							que.push_back(elem);
					}
				}
				result.push_back(a);
			}
			return result;
		}
	}
};