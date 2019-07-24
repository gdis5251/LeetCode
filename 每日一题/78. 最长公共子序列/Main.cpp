#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int GetMaxSubStr(const std::string& lhs, int n, const std::string& rhs, int m)
{
    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lhs[i] == rhs[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    
    return dp[n][m];
        
}

int main(void)
{
    std::string str1;
    std::string str2;
    
    while (std::cin >> str1 >> str2)
    {
        int ans = GetMaxSubStr(str1, str1.size(), str2, str2.size());
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}