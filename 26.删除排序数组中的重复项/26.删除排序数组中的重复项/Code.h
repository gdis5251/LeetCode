int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;

	int cur = 0;
	int pre = 0;

	while (cur < numsSize)
	{
		if (nums[cur] == nums[pre])
			cur++;
		else
		{
			pre++;
			nums[pre] = nums[cur];
			cur++;
		}
	}

	return pre + 1;
}