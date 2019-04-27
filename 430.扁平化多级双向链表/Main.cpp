class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node *cur = head;
                              
        while (cur)
        {
            if (cur->child)
            {
                s.push(cur->next);
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            else if (cur->next == nullptr && !s.empty())
            {
                cur->next = s.top();
                s.pop();
                if (cur->next != nullptr)
                    cur->next->prev = cur;
            }       
            cur = cur->next;                               
        }
                                      
        return head;
                                          
    }

};
