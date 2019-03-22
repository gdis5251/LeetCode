#include <string>

class Solution {
public:
	static std::string reverseStr(std::string s, int k) {
		for (size_t i = 0; i < s.size(); i += 2 * k)
		{
			size_t begin = i;
			size_t end = i + k - 1;
			if (end >= s.size())
				end = s.size() - 1;
			while (begin < end)
			{
				std::swap(s[begin], s[end]);
				++begin;
				--end;
			}
		}

		return s;

	}
};


int main(void)
{
	std::string ans = Solution::reverseStr("a", 2);
	return 0;
}