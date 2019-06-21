/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        std::stack<TreeNode*> s;
        TreeNode* cur = pRootOfTree;
        TreeNode* pre = nullptr;
        bool is_first = true;
        
        while (cur != nullptr || !s.empty())
        {
            // 尽可能让 cur 往左走
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            s.pop();
            
            if (is_first)
            {
                pRootOfTree = cur;
                pre = cur;
                is_first = false;
            }
            else
            {
                pre->right = cur;
                cur->left = pre;
                pre = cur;
            }
            
            cur = cur->right;
        }
        
        return pRootOfTree;
    }
};