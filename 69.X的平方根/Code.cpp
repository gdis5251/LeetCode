/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        int ans = 1;
        while (ans * ans < x)
        {
            ans++;
            if (ans > 46339)
                break;
        }

        if (ans * ans <= x)
            return ans;

        return ans - 1;
    }
};

