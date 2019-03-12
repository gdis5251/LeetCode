#include <vector>

using namespace std;


//暴力法，把两个有序数组重新变成一个有序的数组，找到它的中位数
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i = 0;
		int j = 0;
		vector<int> nums;

		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] <= nums2[j])
				nums.push_back(nums1[i++]);
			else
				nums.push_back(nums2[j++]);
		}

		if (i == nums1.size())
		{
			while (j < nums2.size())
			{
				nums.push_back(nums2[j++]);
			}
		}
		else if (j == nums2.size())
		{
			while (i < nums1.size())
			{
				nums.push_back(nums1[i++]);
			}
		}

		if (nums.size() & 1)
			return nums[nums.size() / 2];

		return (double)(nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
	}
};