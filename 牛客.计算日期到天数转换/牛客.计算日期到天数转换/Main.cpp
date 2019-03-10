#include <iostream>

int main(void)
{
	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;

	while (std::cin >> year >> month >> day)
	{
		int ret = days[month - 1] + day;

		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				ret += 1;
		}

		std::cout << ret << std::endl;
	}

	return 0;
}