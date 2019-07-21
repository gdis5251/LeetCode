class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > dp(m, std::vector<int>(n, 1));
        dp[0][0] = 1;

        // 第一行全部为1
        // for (int i = 1; i < n; i++)
        // {
        //     dp[0][i] = 1;
        // }
        // // 第一列全部为1
        // for (int j = 1; j < m; j++)
        // {
        //     dp[j][0] = 1;
        // }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

