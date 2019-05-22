/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> kv;
        kv['I'] = 1;
        kv['V'] = 5;
        kv['X'] = 10;
        kv['L'] = 50;
        kv['C'] = 100;
        kv['D'] = 500;
        kv['M'] = 1000;

        int ret = 0;
        auto sit = s.begin();
        while(sit != s.end())
        {
            auto found = kv.find(*sit);
            if (sit + 1 != s.end())
            {
                auto next = kv.find(*(sit + 1));
            
                if (sit + 1 != s.end() && next->second > found->second)
                {
                    ret -= found->second;
                }
                else
                {
                    ret += found->second;
                }
            }
            else
            {
                ret += found->second;
            }
            
            
            sit++;
        }

        return ret;
    }
};

