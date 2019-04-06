#include <stack>
#include <vector>
#include <iostream>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
                        
            if (node)
                ans.push_back(node->val);
            else
                continue;
            
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
        return ans;
    }
    
};
