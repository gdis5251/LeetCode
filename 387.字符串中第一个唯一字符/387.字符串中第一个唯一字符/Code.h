#include <string>

class Solution {
public:
	int firstUniqChar(std::string s) {
		if (s.empty())
			return -1;


		int pos = 0;
		for (pos; pos < s.size(); ++pos)
		{
			if (s.find(s[pos], pos + 1) == -1)
			{
				if (s.find(s[pos]) == pos)
					return pos;
			}

		}

		return -1;
	}
};