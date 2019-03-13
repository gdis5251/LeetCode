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




class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n == 0)
		{
			if (m & 1 != 0)
				return 1.0 * nums2[m / 2];

			return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
		}
		else if (m == 0)
		{
			if (n & 1 != 0)
				return 1.0 * nums1[n / 2];

			return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
		}

		int mid1 = (n + m + 1) / 2;
		int mid2 = (n + m + 2) / 2;

		return (FindMid(nums1, 0, nums2, 0, mid1) + FindMid(nums1, 0, nums2, 0, mid2)) / 2.0;
	}

	double FindMid(vector<int>& nums1, int beginN, vector<int>& nums2, int beginM, int mid)
	{
		if (beginN >= nums1.size())
			return nums2[beginM + mid - 1];

		if (beginM >= nums2.size())
			return nums1[beginN + mid - 1];

		if (mid == 1)
			return min(nums1[beginN], nums2[beginM]);

		int midN = INT_MAX;
		int midM = INT_MAX;

		if (beginN + mid / 2 - 1 < nums1.size())
			midN = nums1[beginN + mid / 2 - 1];

		if (beginM + mid / 2 - 1 < nums2.size())
			midM = nums2[beginM + mid / 2 - 1];

		if (midN < midM)
			return FindMid(nums1, beginN + mid / 2, nums2, beginM, mid - mid / 2);
		return FindMid(nums1, beginN, nums2, beginM + mid / 2, mid - mid / 2);


	}
};