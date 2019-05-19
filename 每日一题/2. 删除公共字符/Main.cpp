#include <iostream>
#include <string>

int main(void)
{
	std::string dest; //这个是待删除字符串
	std::string src;  //根据该字符串来删除

	while (std::getline(std::cin, dest) && std::getline(std::cin, src))
	{
		std::string::iterator dit = dest.begin();
		std::string::iterator sit = src.begin();

		//遍历dest字符串，遇到相同的删除
		//每次遇到一个字符还必须将src遍历一遍，所以这是个O(N^2)的算法
		while (dit != dest.end())
		{
			int flag = 0;

			while (sit != src.end())
			{
				if (*dit == *sit)
				{
					flag = 1;
					dit = dest.erase(dit);
					break;
				}
				else
				{
					flag = 0;
					sit++;
				}
			}

			if (flag == 0)
				dit++;
			sit = src.begin();
		}

		std::cout << dest.c_str() << std::endl;
	}
	return 0;
}