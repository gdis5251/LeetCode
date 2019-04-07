/**
 * Definition for a binary tree node.
 **/

 
 //CPP
#include <iostream>
#include <vector>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:

	void _inorderTraversal(TreeNode *root, std::vector<int>& array)
	{
		if (root == NULL)
			return;

		_inorderTraversal(root->left, array);
		array.push_back(root->val);
		_inorderTraversal(root->right, array);
	}

	std::vector<int> inorderTraversal(TreeNode* root) {

		std::vector<int> array;

		_inorderTraversal(root, array);

		return array;
	}
};



//C
int *array;
int size;

void _inorderTraversal(struct TreeNode *root)
{
	if (root == NULL)
		return;

	_inorderTraversal(root->left);
	array[size++] = root->val;
	_inorderTraversal(root->right);


}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	size = 0;
	array = (int *)malloc(sizeof(int) * 100 * 10000);

	_inorderTraversal(root);

	*returnSize = size;
	return array;
}

//non recursive
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> s;

		TreeNode *cur = root;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}

			cur = s.top();
			ans.push_back(cur->val);

			s.pop();
			cur = cur->right;
		}

		return ans;
	}
};