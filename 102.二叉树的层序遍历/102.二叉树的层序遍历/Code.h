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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;

		ans.resize(10000);
		q.push(root);
		size_t i = 0;

		for (i = 0; !q.empty(); i++)
		{
			if (q.front() == NULL)
				break;

			size_t sz = q.size();
			for (size_t j = 0; j < sz; j++)
			{
				ans[i].push_back(q.front()->val);
				TreeNode *node = q.front();
				q.pop();

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}

		}

		ans.resize(i);
		return ans;
	}
};