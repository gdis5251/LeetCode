class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        // 首先第一行和第一列初始化为 1
        // 因为一直往右走 或 一直往下走只是一种走法
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }
        
        // 其他都位置都可能来自它的上面或左边，所以相加就行
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