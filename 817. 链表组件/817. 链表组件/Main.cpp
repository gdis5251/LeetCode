#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
	ListNode(int x) 
		:val(x)
		,next(nullptr) 
	{}
};
 
class Solution {
public:
	static int numComponents(ListNode* head, vector<int>& G) {
		ListNode *cur = head;
		int flag = 1;
		size_t count = 0;
		size_t isContinue = 0;

		while (cur != nullptr)
		{
			vector<int>::iterator it = G.begin();
			it = find(G.begin(), G.end(), cur->val);

			if (it != G.end() && isContinue == 0)
			{
				flag = 1;
				isContinue = 1;
			}
			else if (it != G.end() && isContinue != 0)
			{
				flag = 0;
			}
			else
			{
				flag = 0;
				isContinue = 0;
			}

			if (flag)
				count++;

			if (it != G.end())
			{
				G.erase(it);
			}

			cur = cur->next;
		}

		return count;
	}
};


int main(void)
{
	struct ListNode *head = new struct ListNode(0);//0 1 2 3
	struct ListNode *tail = head;
	for (int i = 1; i <= 3; i++)
	{
		struct ListNode *cur = new struct ListNode(i);
		tail->next = cur;
		cur->next = nullptr;

		tail = cur;
	}

	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);

	int res = Solution::numComponents(head, v);


	return 0;
}