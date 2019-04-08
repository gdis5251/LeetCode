#include <iostream>
#include <vector>
#include <stack>

using namespace std;
  //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	static vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode *> s;

		TreeNode *cur = root;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}

			cur = s.top();
			if (cur->right == NULL)
			{
				ans.push_back(cur->val);
				s.pop();

				if (!s.empty())
				{
					TreeNode *new_cur = s.top();
					if (new_cur->left == cur)
						new_cur->left = NULL;
					else if (new_cur->right == cur)
						new_cur->right = NULL;
				}
			}
			cur = cur->right;
		}

		return ans;
	}
};

int main(void)
{
	struct TreeNode t1(1);
	struct TreeNode t2(3);
	struct TreeNode t3(2);

	struct TreeNode *root = &t1;
	root->right = &t2;
	root->right->left = &t3;

	Solution::postorderTraversal(root);
	
	
	return 0;
}