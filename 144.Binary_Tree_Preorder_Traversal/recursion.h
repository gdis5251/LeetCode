#include <iostream>
#include <vector>

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
    void _preorderTraversal(TreeNode *root, vector<int>& res)
    {
        if (root == NULL)          
            return;

            res.push_back(root->val);
            _preorderTraversal(root->left, res);
            _preorderTraversal(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        _preorderTraversal(root, res);
                                    
        return res;
       }
};
