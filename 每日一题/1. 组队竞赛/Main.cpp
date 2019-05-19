#include <iostream>
#include <vector>
#include "Solution.hpp"

int main(void)
{
	int n = 0;
	while (std::cin >> n)
	{
		//共有多少个人
		const int count = 3 * n;

		//输入所有人的成绩
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