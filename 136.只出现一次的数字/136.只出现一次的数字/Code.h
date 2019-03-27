#include <vector>
using namespace std;

//挨个抑或，最后只剩下只出现一次的数字
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int>::iterator nit = nums.begin();
		int res = 0;
		while (nit != nums.end())
		{
			res ^= *nit;
			nit++;
		}

		return res;
	}
};

//C++11
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (const auto&e : nums)
		{
			res ^= e;
		}

		return res;
	}
};