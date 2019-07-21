class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() || dict.empty())
        {
            return false;

        }

        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            // 遍历之前的状态
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
