#include <iostream>
#include <vector>
#include "Solution.hpp"

int main(void)
{
	int n = 0;
	while (std::cin >> n)
	{
		//���ж��ٸ���
		const int count = 3 * n;

		//���������˵ĳɼ�
		std::vector<int> grade;
		grade.resize(count);
		for (int i = 0; i < count; ++i)
		{
			std::cin >> grade[i];
		}

		const int ans = GetHighLevelGrade(grade, n);

		std::cout << ans << std::endl;
	}
	return 0;
}