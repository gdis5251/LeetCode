/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= target)
                return i;
        }

        return nums.size();
    }
};

