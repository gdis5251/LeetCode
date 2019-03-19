#include <string>

class Solution {
public:
	int firstUniqChar(std::string s) {
		if (s.empty())
			return -1;

		std::string book(s.size(), '\0');

		int pos = 0;
		for (pos; pos < s.size(); ++pos)
		{
			if (s.find(s[pos], pos + 1) != -1)
			{
				book.push_back(s[pos]);
			}
			else
			{
				if (book.find(s[pos]) == -1)
					return pos;
			}
		}

		return -1;
	}
};