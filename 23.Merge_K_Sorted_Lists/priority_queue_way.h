#include <iostream>
#include <vector>
#include <queue>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode*>& lists)
    {
        auto cmp = [](const ListNode *left, const ListNode *right)
        {
            return left->val > right->val;
        };
        std::priority_queue<ListNode *, std::vector<ListNode*>, decltype(cmp) > pq(cmp);

        for (const auto& e : lists)
        {
            ListNode *cur = e;
            while (cur != nullptr)
            {
                pq.push(cur);
                ListNode *next = cur->next;
                cur->next = nullptr;
                cur = next;
            }
        }

        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        
        while (!pq.empty())
        {
            if (head == nullptr)
            {
                head = pq.top();
                cur = head;
                pq.pop();
            }
            else
            {
                cur->next = pq.top();
                cur = cur->next;
                pq.pop();
            }
        }

        return head;

    }
};
