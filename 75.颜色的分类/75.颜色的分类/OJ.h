//����һ���Լ�дһ�����ţ�Ȼ���ô�ͳ������ʵ������

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


//����������·����
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
				//����֮��nums[i]ֻ����1������Ҫ������һ��
				i++;
			}
		}
	}
};