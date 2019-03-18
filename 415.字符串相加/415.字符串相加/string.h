#include <iostream>
#include <string>

class Solution {
public:
	static std::string addStrings(std::string num1, std::string num2) {
		int n = num1.size();
		int m = num2.size();

		std::string::reverse_iterator nit = num1.rbegin();
		std::string::reverse_iterator mit = num2.rbegin();

		int maxLenth = n > m ? n : m;
		std::string ans(maxLenth + 1, '0');
		std::string::reverse_iterator ait = ans.rbegin();

		for (; nit < num1.rend() && mit < num2.rend(); nit++, mit++)
		{
			*ait += ((*nit - '0') + (*mit - '0'));

			//判断是否要进位
			if (*ait > '9')
			{
				*(ait + 1) += 1;
				*ait -= 10;
			}

			ait++;
		}


		while (nit != num1.rend())
		{
			*ait += (*nit - '0');
			//判断是否要进位
			if (*ait > '9')
			{
				*(ait + 1) += 1;
				*ait -= 10;
			}
			ait++;
			nit++;
		}

		while (mit != num2.rend())
		{
			*ait += (*mit - '0');
			//判断是否要进位
			if (*ait > '9')
			{
				*(ait + 1) += 1;
				*ait -= 10;
			}
			ait++;
			mit++;
		}

		if (ans[0] == '0')
		{
			std::string rev;
			return rev.assign(ans, 1, maxLenth);
		}


		return ans;
	}
};