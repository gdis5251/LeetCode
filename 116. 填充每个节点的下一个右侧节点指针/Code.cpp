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
        if (root == nullptr)
            return nullptr;
        
        queue<Node*> q;
        q.push(root);
        Node* cur = q.front();
        while (!q.empty())
        {
            size_t sz = q.size();
            
            for (size_t i = 0; i < sz; i++)
            {
                q.pop();
                if (i == sz - 1)
                    cur->next = nullptr;
                else
                    cur->next = q.front();
                
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                
                cur = q.front();
            }
            
        }
        
        return root;
    }
};