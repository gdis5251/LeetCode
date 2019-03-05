//方法一，自己写一个快排，然后用传统快排来实现排序

class Solution {
public:
	int partition(vector<int>& nums, int left, int right)
	{
		int div = left;

		while (left < right)
		{
			while (left < right && nums[right] >= nums[div])
				right--;

			while (left < right && nums[left] <= nums[div])
				left++;

			if (left < right)
			{
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
		}

		int temp = nums[right];
		nums[right] = nums[div];
		nums[div] = temp;

		return right;
	}




	void QuickSort(vector<int>& nums, int left, int right)
	{
		if (left >= right)
			return;

		int div = partition(nums, left, right);

		QuickSort(nums, left, div - 1);

		QuickSort(nums, div + 1, right);


	}




	void sortColors(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
	}
};


//方法二：三路快排
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = -1;
		int two = nums.size();

		for (int i = 0; i < two;)
		{
			if (nums[i] == 1)
				i++;
			else if (nums[i] == 2)
			{
				two--;
				swap(nums[i], nums[two]);

			}
			else
			{
				zero++;
				swap(nums[i], nums[zero]);
				//换完之后nums[i]只能是1，所以要往后走一步
				i++;
			}
		}
	}
};