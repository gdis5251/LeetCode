class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
			return false;

		int max = nums[0];
		/*
		����һ��max����
		������ʱ�����ǰ������ֱ�max����˵������ǰ����������ֶ��󣬾Ͳ��ñ�ǰ�����
		�����maxС���ڸ�ǰ������ֱ�
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