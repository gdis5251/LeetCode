class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty())
			return 0;


		sort(nums.begin(), nums.end());
		size_t i = 0;
		while (i < nums.size() - 1)
		{
			if (nums[i] == nums[i + 1])
			{
				i += 3;
			}
			else
				break;
		}

		return nums[i];
	}
};