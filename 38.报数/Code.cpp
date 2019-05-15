/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        if (n == 1)
            return "1";     

        string ans = "1";
        for (int num = 2; num <= n; num++)
        {
            int i = 0; 
            int j = 0;

            string tmp = ans;
            ans.clear();

            while (i < tmp.size() && j < tmp.size())
            {
                //找到第一个跟前一个子字符不一样的数字
                while (tmp[i] == tmp[j] && j < tmp.size())
                    j++;

                ans += to_string(j - i);
                ans += tmp[i];
                i = j;
            }
        }

        return ans;
    }
};

