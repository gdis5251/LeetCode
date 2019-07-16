class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
        {
            return s;
        }
        
        int max_len = 1;
        std::string ans = s.substr(0, 1);
        
        std::vector<std::vector<bool> >dp(s.size(), std::vector<bool>(s.size(), false));
        dp[0][0] = true;
        
        for (int r = 1; r < s.size(); r++)
        {
            for (int l = 0; l < r; l++)
            {
                if ((s[l] == s[r]) && (r - l <= 2 || dp[r - 1][l + 1]))
                {
                    dp[r][l] = true;
                    
                    if (r - l + 1 > max_len)
                    {
                        max_len = r - l + 1;
                        ans = s.substr(l, r - l + 1);
                    }
                }
            }
        }
        
        return ans;
    }
};