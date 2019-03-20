class Solution {
public:
	int maxArea(vector<int>& height) {	//±©Á¦·¨
		int max = 0;

		for (int i = 0; i < height.size(); i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				if (i == j)
					continue;

				int ml = 0;

				if (height[i] <= height[j])
				{
					ml = height[i] * (j - i);
				}
				else
				{
					ml = height[j] * (j - i);
				}

				if (ml > max)
					max = ml;
			}
		}
		return max;
	}
};