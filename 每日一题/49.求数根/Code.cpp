// write your code here cpp
#include <iostream>

int GetRootNum(int num)
{
	int tmp = num;
	bool is_continue = true;

	while (is_continue)
	{
		if (tmp < 10)
		{
			return tmp;
		}
		else
		{
			// 把 tmp 的每一位加起来,赋值给 tmp
			int sum = 0;
			while (tmp > 9)
			{
				sum += tmp % 10;
				tmp /= 10;
			}
			sum += tmp;
			tmp = sum;
		}
	}

	return 0;
}

int main(void)
{
	int num = 0;
	while (std::cin >> num)
	{
		int ans = GetRootNum(num);

		std::cout << ans << std::endl;
	}

	return 0;
}