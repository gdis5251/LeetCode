# LeetCode 430. 扁平化多级双向链表

#### 题目描述：

您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

 

**示例:**

```
输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
```

 

**以上示例的说明:**

给出以下多级双向链表:

![multilevellinkedlist](F:\LeetCode\430.扁平化多级双向链表\multilevellinkedlist.png)

 

我们应该返回如下所示的扁平双向链表:

![multilevellinkedlistflattened](F:\LeetCode\430.扁平化多级双向链表\multilevellinkedlistflattened.png)

#### 解题思路：

这道题我们画个图来试着理解一下：

![解题思路](F:\LeetCode\430.扁平化多级双向链表\解题思路.png)

我们跟着红线，然后把这些结点贯穿在一起。其实难点就是每次向下走之前，把后面的那一个结点记下来，以便后面连接用。那么就用一个栈来记录，刚好可以按照顺序，从下往上连。

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node *cur = head;
        
        while (cur)
        {
            if (cur->child) //注意：这里就算下一个结点是空都要入栈。
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
```

