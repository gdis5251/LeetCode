/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool getPath(TreeNode *cur, TreeNode *node, stack<TreeNode*>& s)
	{
		if (cur == NULL)
			return false;

		//����ջ
		s.push(cur);
		//���ҵ�����
		if (cur == node)
			return true;

		if (getPath(cur->left, node, s))
			return true;
		if (getPath(cur->right, node, s))
			return true;

		//˵����ǰ��㲻��·����
		s.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> sp;
		stack<TreeNode*> sq;

		getPath(root, p, sp);
		getPath(root, q, sq);

		while (!sp.empty() && !sq.empty())
		{
			if (sp.size() > sq.size())
			{
				while (sp.size() != sq.size())
				{
					sp.pop();
				}
			}
			else if (sp.size() < sq.size())
			{
				while (sp.size() != sq.size())
				{
					sq.pop();
				}
			}

			if (sp.top() == sq.top())
				return sq.top();

			sq.pop();
			sp.pop();
		}

		return NULL;
	}
};