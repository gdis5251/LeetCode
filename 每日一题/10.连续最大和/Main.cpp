#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
        size_t len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        
        std::vector<int> dp(len, 0);
        dp[0] = nums[0];
        int max_num = dp[0];

        for (size_t i = 1; i < len; ++i)
        {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];

            max_num = std::max(dp[i], max_num);
        }

        return max_num;
    }

int main(void)
{
    std::vector<int> nums;
    int num = 0;
    
    while (std::cin.peek() != '\n')
    {
        std::cin >> num;
        nums.push_back(num);
    }
    
    int max = maxSubArray(nums);
    std::cout << max << std::endl;
    
    return 0;
}
