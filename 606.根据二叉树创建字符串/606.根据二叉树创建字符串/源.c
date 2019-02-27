/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char *str;
int size;

void preorderTraversal(struct TreeNode *root)
{
	if (root == NULL)
		return;

	int n = sprintf(str + size, "%d", root->val);
	size += n;

	if (root->left)
	{
		str[size++] = '(';
		preorderTraversal(root->left);
		str[size++] = ')';
	}
	else if (root->right)
	{
		str[size++] = '(';
		str[size++] = ')';
	}

	if (root->right)
	{
		str[size++] = '(';
		preorderTraversal(root->right);
		str[size++] = ')';
	}

}


char* tree2str(struct TreeNode* t) {
	str = (char *)malloc(sizeof(char) * 100 * 10000);
	size = 0;

	if (t == NULL)
		return str;

	preorderTraversal(t);

	str[size] = '\0';

	return str;


}