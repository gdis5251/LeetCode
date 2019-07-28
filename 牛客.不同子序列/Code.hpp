class Solution {
public:
    int numDistinct(string S, string T) {
        int len1 = S.size();
        int len2 = T.size();

        std::vector<std::vector<int> > dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= len1; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= len2; j++)
            {
                if (S[i - 1] == T[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

                }
                else
                {
                    dp[i][j] = dp[i - 1][j];

                }

            }

        }

        return dp[len1][len2];

    }

};
