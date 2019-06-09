#include <iostream>
#include <string>
std::string LongIntAdd(std::string& num1, std::string& num2)
{
	std::string ans;
	int len = num1.size();
	if (num2.size() > num1.size())
		len = num2.size();
	ans.resize(len + 1, 0);
	std::string::reverse_iterator n1it = num1.rbegin();
	std::string::reverse_iterator n2it = num2.rbegin();
	std::string::reverse_iterator ait = ans.rbegin();
	int flag = 0;
	while (n1it != num1.rend() && n2it != num2.rend())
	{
		*ait += flag;
		*ait += (*n1it - '0') + (*n2it - '0');
		if (*ait > 9)
		{
			flag = 1;
			*ait %= 10;
		}
		else
		{
			flag = 0;
		}
		*ait += '0';
		ait++;
		n1it++;
		n2it++;
	}
	if (n2it == num2.rend())
	{
		while (n1it != num1.rend())
		{
			*ait += flag;
			*ait += *n1it - '0';
			if (*ait > 9)
			{
				flag = 1;
				*ait %= 10;
			}
			else
			{
				flag = 0;
			}
			*ait += '0';
			ait++;
			n1it++;
		}
	}
	else if (n1it == num1.rend())
	{
		while (n2it != num2.rend())
		{
			*ait += flag;
			*ait += *n2it - '0';
			if (*ait > 9)
			{
				flag = 1;
				*ait %= 10;
			}
			else
			{
				flag = 0;
			}
			*ait += '0';
			ait++;
			n2it++;
		}
	}
	// 处理最后一次进位
	if (flag == 1)
	{
		*ait += flag + '0';
	}
	if (ans[0] == 0)
	{
		std::string ret = ans.substr(1);
		return ret;
	}
	return ans;
}
int main(void)
{
	std::string num1;
	std::string num2;
	while (std::cin >> num1 >> num2)
	{
		std::string ans = LongIntAdd(num1, num2);
		std::cout << ans.c_str() << std::endl;
	}
	return 0;
}