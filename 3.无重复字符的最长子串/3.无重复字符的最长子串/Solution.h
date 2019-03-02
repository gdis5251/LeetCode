#include <windows.h>
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freg[256] = { 0 };
		int i = 0;
		int j = 0;
		int ans = 0;

		while (i < s.size() && j < s.size())
		{
			if (freg[s[j]] == 0)
			{
				freg[s[j++]]++;
				ans = max(ans, j - i);
			}
			else
			{
				freg[s[i++]]--;
			}
		}

		return ans;
	}
};