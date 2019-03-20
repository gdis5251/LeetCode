//暴力法，将所有的结果都实现一遍
class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;

		for (int i = 0; i < height.size(); i++)
		{
			for (int j = 0; j < height.size(); j++)
			{
				if (i == j)
					continue;

				int ml = 0;

				if (height[i] <= height[j])
				{
					if (i < j)
					{
						ml = height[i] * (j - i);
					}
					else
					{
						ml = height[i] * (i - j);
					}

				}
				else
				{
					if (i < j)
					{
						ml = height[j] * (j - i);
					}
					else
					{
						ml = height[j] * (i - j);
					}
				}

				if (ml > max)
					max = ml;
			}
		}
		return max;
	}
};