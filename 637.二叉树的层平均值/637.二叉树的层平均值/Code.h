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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		queue<TreeNode*> q;
		q.push(root);
		size_t sz = 0;
		double aver = 0;
		double sum = 0;

		while (!q.empty())
		{
			sum = 0;
			sz = q.size();

			for (size_t j = 0; j < sz; j++)
			{
				sum += q.front()->val;

				if (q.front()->left)
					q.push(q.front()->left);
				if (q.front()->right)
					q.push(q.front()->right);

				q.pop();
			}

			aver = sum / sz;
			ans.push_back(aver);
		}

		return ans;
	}
};