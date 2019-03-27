class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> nums;
		nums.resize(numRows);
		for (size_t i = 0; i < numRows; ++i)
		{
			nums[i].resize(i + 1, 0);
			nums[i][0] = 1;
			nums[i][nums[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = 0; j < nums[i].size(); ++j)
			{
				if (nums[i][j] == 0)
				{
					nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];

				}

			}
		}


		return nums;
	}
};