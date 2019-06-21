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
    int idx = 0;
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        
        // 先一个一个拿出来前序遍历的最前面的结点
        // 也就是对于当前来说的根结点
        int data = preorder[idx++];
        
        for (int i = start; i <= end; i++)
        {
            if (data == inorder[i])
            {
                TreeNode* root = new TreeNode(data);
                root->left = helper(preorder, inorder, start, i - 1);
                root->right = helper(preorder, inorder, i + 1, end);

                return root;
            }
        }
        
        return nullptr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, inorder.size() - 1);    
    }
};