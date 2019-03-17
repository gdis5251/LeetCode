#include <iostream>
#include <string>

class Solution {
public:
	int StrToInt(string str) {
		std::string::iterator sit = str.begin();


		int ans = 0;
		int flag = 1;
		for (sit; sit < str.end(); sit++)
		{
			ans *= 10;

			if (*sit >= 48 && *sit <= 56)
			{
				ans += *sit - 48;
			}

			else if (*sit == '-' || *sit == '+')
			{
				if (*sit == '-')
					flag = -1;
			}

			else
				return 0;


		}

		return ans * flag;
	}
};