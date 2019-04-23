class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;

		for (const auto& e : nums)
		{
			pq.push(e);
		}

		for (int i = 0; i < k - 1; i++)
		{
			pq.pop();
		}

		return pq.top();
	}
};

//ÓÅ»¯
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

		for (size_t i = 0; i < k; i++)
		{
			pq.push(nums[i]);
		}

		for (size_t j = k; j < nums.size(); j++)
		{
			if (nums[j] > pq.top())
			{
				pq.pop();
				pq.push(nums[j]);
			}
		}

		return pq.top();
	}
};