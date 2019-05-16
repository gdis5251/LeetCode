/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int max_num = dp[0];

        for (size_t i = 1; i < len; ++i)
        {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];

            max_num = max(dp[i], max_num);
        }

        return max_num;
    }
};