#pragma once
#include <vector>
#include <algorithm>

int GetHighLevelGrade(std::vector<int>& grade, int n)
{
	//������
	sort(grade.begin(), grade.end());

	//Ȼ����ɼ��ֳ����飬ÿ��n��
	//�����м�����ĺ;���
	long long ans = 0;
	for (int i = n; i <= (n * 3) - 2; i += 2)
	{
		ans += grade.at(i);
	}

	return ans;
}