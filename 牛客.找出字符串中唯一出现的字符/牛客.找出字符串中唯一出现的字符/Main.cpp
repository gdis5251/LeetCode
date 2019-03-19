#include <string>
#include <iostream>


/*
int main(void)
{
	std::string s;

	std::cin >> s;
	int pos;
	for (pos = 0; pos < s.size(); ++pos)
	{
		if (s.find(s[pos], pos + 1) == -1)
		{
			if (s.find(s[pos]) == pos)
			{
				std::cout << s[pos] << std::endl;
				break;
			}
		}
	}
	if (pos >= s.size())
		std::cout << -1 << std::endl;

	return 0;
}*/

int main(void)
{
	int book[256] = { 0 };
	std::string s;
	std::cin >> s;
	for (size_t i = 0; i < s.size(); i++)
	{
		book[s[i]] += 1;
	}

	size_t i;
	for (i = 0; i < s.size(); i++)
	{
		if (book[s[i]] == 1)
		{
			std::cout << s[i] << std::endl;
			break;
		}
	}

	if (i >= s.size())
		std::cout << -1 << std::endl;

	return 0;

}