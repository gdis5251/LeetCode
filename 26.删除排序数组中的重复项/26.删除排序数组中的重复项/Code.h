
//c语言做法

//int removeDuplicates(int* nums, int numsSize) {
//	if (numsSize == 0)
//		return 0;
//
//	int pre = 0;
//	int cur = 1;
//
//	while (cur < numsSize)
//	{
//		if (nums[pre] != nums[cur])
//		{
//			nums[++pre] = nums[cur++];
//		}
//		else
//		{
//			cur++;
//		}
//	}
//
//	return pre + 1;
//}



//c++用vector的接口做法，但是慢
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int>::iterator pos = nums.begin();
		vector<int>::iterator cur = nums.begin() + 1;
		while (cur != nums.end())
		{
			if (*pos == *cur)
			{
				cur = nums.erase(cur);
				continue;
			}

			pos++;
			cur++;
		}


		return nums.size();
	}
};