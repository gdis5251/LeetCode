#include <string>
#include <iostream>

int firstUniqChar(std::string s) {
	int book[123] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		book[s[i]]++;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (1 == book[s[i]])
			return i;
	}

	return -1;

}
int main(void)
{
	std::string s;
	while (std::cin >> s)
	{
		int pos = firstUniqChar(s);

		if (pos == -1)
			std::cout << -1 << std::endl;
		else
			std::cout << s[pos] << std::endl;
	}
	return 0;

}