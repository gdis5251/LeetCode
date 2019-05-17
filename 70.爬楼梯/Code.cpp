/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        int stepOne = 1;
        int stepTwo = 0;
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            ret = stepOne + stepTwo;
            stepTwo = stepOne;
            stepOne = ret;
        }

        return ret;
    }
};

