/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> qu;
        qu.push(root);
        
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                Node* cur = qu.front();
                qu.pop();
                
                if (cur == nullptr)
                    return nullptr;
                
                // 说明已经是该层的最后一个了
                if (i == size - 1)
                {
                    cur->next = nullptr;
                }
                else
                {
                    cur->next = qu.front();
                }
                
                // 插入 cur 的左右子树
                if (cur->left != nullptr)
                {
                    qu.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    qu.push(cur->right);
                }
            }
        }
        
        return root;
    }
};