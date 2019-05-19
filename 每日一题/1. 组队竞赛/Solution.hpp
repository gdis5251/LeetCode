#pragma once
#include <vector>
#include <algorithm>

int GetHighLevelGrade(std::vector<int>& grade, int n)
{
	//先排序
	sort(grade.begin(), grade.end());

	//然后最成绩分成三组，每组n个
	//返回中间那组的和就行
	long long ans = 0;
	for (int i = n; i <= (n * 3) - 2; i += 2)
	{
		ans += grade.at(i);
	}

	return ans;
}