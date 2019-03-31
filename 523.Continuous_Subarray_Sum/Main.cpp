#include <vector>
#include <iostream>

class Solution {
public:
    static bool checkSubarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
                        
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (size_t j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (k == 0 && j > i && sum == 0)
                    return true;
                if (k != 0 && j > i && sum % k == 0)
                    return true;
                              
            }
                      
        }
        return false;
    }
};

int main(void)
{
    int array[5] = {23, 2, 4, 6, 7};
    std::vector<int> nums(array, array + sizeof(array) / sizeof(int));
    int k = 6;

    bool isTrue = Solution::checkSubarraySum(nums, 6);
    std::cout << isTrue << std::endl;

    return 0;
}





