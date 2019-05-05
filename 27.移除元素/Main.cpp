#include <vector>
#include <algorithm>

using namespace std;

/* 方法一
class Solution {
public:
	static int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator pos = nums.begin();
		size_t index = 0;

		while (1)
		{
			pos = find(nums.begin(), nums.end(), val);
			if (pos == nums.end())
				break;
			nums.erase(pos);
			pos = nums.begin();
		}

		return nums.size();
	}
};
*/

// 方法二
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};


int main(void)
{
	int arr[8] = { 3, 1, 3, 3, 3 };
	vector<int> nums(arr, arr + 5);
	Solution::removeElement(nums, 3);
	return 0;
}