#include <iostream>
#include <string>

int PageTurn(std::string& str, int n)
{
	int pos = 1; // 指当前在这个显示器的第几个位置上
	int num = 1; // 表示当前在第几首歌上
	int down = 4;
	if (n < 4)
		down = n;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == 'U')
		{
			if (num == 1)
			{
				num = n;
				pos = down;
			}
			else
			{
				num--;
				if (pos != 1)
					pos--;
			}
		}
		else
		{
			if (num == n)
			{
				num = 1;
				pos = 1;
			}
			else
			{
				num++;
				if (pos != down)
					pos++;
			}
		}
	}
    int num_print = 4;
    if (n < 4)
        num_print = n;

	for (int j = 0; j < num_print; j++)
	{
		std::cout << num - pos + 1 + j << " ";
	}

	std::cout << std::endl;

	return num;
}

int main(void)
{
	int n = 0;
	while (std::cin >> n)
	{
		std::string in_str;
		std::cin >> in_str;

		int ans = PageTurn(in_str, n);

		std::cout << ans << std::endl;
	}

	return 0;
}