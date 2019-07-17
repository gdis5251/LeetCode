class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        std::vector<std::vector<long long> > dp(row, std::vector<long long>(col, 0));
        
        for (int i = 0; i < row; i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < col; i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }
            else
            {
                dp[0][i] = 1;
            }
        }
        
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[row - 1][col - 1];
    }
};