class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
        {
            return 0;

        }

        std::vector<std::vector<int> > dp(triangle);

        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];

            }

        }

        return dp[0][0];

    }

};
