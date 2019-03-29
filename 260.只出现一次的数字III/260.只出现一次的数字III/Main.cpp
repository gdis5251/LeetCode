#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		

		int ans = 0;
		size_t begin = 0;

		while (begin < nums.size())
		{
			ans ^= nums[begin];

			begin++;
		}

		//找二进制第一个为1的位
		int bit = 1;
		while (1)
		{
			if ((bit & ans) != 0)
				break;

			bit <<= 1;
		}

		begin = 0;
		int res1 = 0;
		int res2 = 0;

		while (begin < nums.size())
		{
			if ((nums[begin] & bit) != 0)
			{
				res1 ^= nums[begin];
			}
			else
			{
				res2 ^= nums[begin];
			}

			begin++;
		}

		vector<int> rev;
		rev.push_back(res1);
		rev.push_back(res2);

		return rev;
	}
};

int main(void)
{
	Solution v1;
	vector<int> nums;
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(5);

	v1.singleNumber(nums);

	return 0;
}