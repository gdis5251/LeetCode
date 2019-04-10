#include "priority_queue_way.h"

using namespace std;

int main(void)
{
    //1 4 5
    //1 3 4
    //2 6
    struct ListNode a1(1);
    struct ListNode a2(4);
    struct ListNode a3(5);
                
    struct ListNode b1(1);
    struct ListNode b2(3);
    struct ListNode b3(4);
       
    struct ListNode c1(2);
    struct ListNode c2(6);
       
    a1.next = &a2;
    a2.next = &a3;
       
    b1.next = &b2;
    b2.next = &b3;
       
    c1.next = &c2;
       
    vector<ListNode*> lists;
    lists.push_back(&a1);
    lists.push_back(&b1);
    lists.push_back(&c1);
    
    Solution a;
    struct ListNode* ans = a.mergeKLists(lists);

    for (struct ListNode* i = ans; i != nullptr; i = i->next)
    {
        cout << i->val << " ";
    }
    cout << endl;
        
    return 0;
                                                                                    
}
