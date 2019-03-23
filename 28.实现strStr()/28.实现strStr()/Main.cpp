#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack == "" && needle == "")
			return 0;

		if (needle == "")
			return 0;

		size_t h = 0;
		size_t n = 0;
		string cpy;
		cpy.reserve(needle.size());
		size_t pos = 0;

		for (h; h < haystack.size(); h++, pos++)
		{
			if (haystack[h] == needle[n])
			{
				cpy = haystack.substr(h, needle.size());
				if (cpy == needle)
					return h;
			}
		}

		return -1;
	}
};
int main(void)
{
	int a = Solution::strStr("aaa", "aaaa");
	return 0;
}