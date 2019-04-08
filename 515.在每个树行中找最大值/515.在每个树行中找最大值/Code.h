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
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);
		size_t sz = 0;
		int max = INT_MIN;

		while (!q.empty() && root != NULL)
		{
			max = INT_MIN;
			sz = q.size();

			for (size_t j = 0; j < sz; j++)
			{
				if (q.front()->val > max)
					max = q.front()->val;

				if (q.front()->left)
					q.push(q.front()->left);
				if (q.front()->right)
					q.push(q.front()->right);

				q.pop();
			}


			ans.push_back(max);
		}

		return ans;
	}
};