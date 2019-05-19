#include <iostream>
#include <string>

int main(void)
{
	std::string dest; //����Ǵ�ɾ���ַ���
	std::string src;  //���ݸ��ַ�����ɾ��

	while (std::getline(std::cin, dest) && std::getline(std::cin, src))
	{
		std::string::iterator dit = dest.begin();
		std::string::iterator sit = src.begin();

		//����dest�ַ�����������ͬ��ɾ��
		//ÿ������һ���ַ������뽫src����һ�飬�������Ǹ�O(N^2)���㷨
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