class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
			return false;

		int max = nums[0];
		/*
		设置一个max变量
		遍历的时候，如果前面的数字比max还大，说明它比前面的所有数字都大，就不用比前面的了
		如果比max小，在跟前面的数字比
		*/

		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
			}
			else if (nums[i] == max)
			{
				return true;
			}
			else
			{
				for (int j = (int)i - 1; j >= 0; j--)
				{
					if (nums[j] == nums[i])
						return true;

				}
			}
		}

		return false;
	}
};