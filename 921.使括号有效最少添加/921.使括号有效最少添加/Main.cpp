#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> sta;
		while (!S.empty())
		{
			if (!sta.empty() && sta.top() == '(' &&  S[0] == ')')
			{
				sta.pop();
				S.erase(0, 1);

				continue;
			}

			sta.push(S[0]);
			S.erase(0, 1);
		}

		return sta.size();
	}
};


int main(void)
{
	string s("(((");
	Solution a;
	a.minAddToMakeValid(s);
	return 0;
}