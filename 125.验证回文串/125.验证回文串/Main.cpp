#include <string>


class Solution {
public:
	static bool isPalindrome(std::string s) {
		if (s.empty())
			return true;

		std::string cpy;
		for (auto c : s)
		{
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
				cpy.push_back(c);
		}

		std::string reverse_cpy(cpy);
		int begin = 0;
		int end = reverse_cpy.size() - 1;

		while (begin < end)
		{
			std::swap(reverse_cpy[begin], reverse_cpy[end]);
			++begin;
			--end;
		}

		std::string::iterator cit = cpy.begin();
		std::string::iterator rit = reverse_cpy.begin();

		while (cit < cpy.end())
		{
			if (*cit >= '0' && *cit <= '9')
			{
				if (*cit == *rit)
				{
					cit++;
					rit++;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (*cit >= *rit)
				{
					if (*cit == *rit || *cit - 32 == *rit)
					{
						cit++;
						rit++;
					}
					else
						return false;
				}
				else
				{
					if (*rit - 32 == *cit)
					{
						cit++;
						rit++;
					}
					else
						return false;
				}
			}
		}

		return true;
	}
};


int main(void)
{
	std::string s("0P");
	bool i = Solution::isPalindrome(s);

	return 0;
}