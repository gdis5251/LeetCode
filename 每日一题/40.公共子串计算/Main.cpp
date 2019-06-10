#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    std::string str1;
    std::string str2;
    
    while (std::cin >> str1 >> str2)
    {
        size_t len1 = str1.size();
        size_t len2 = str2.size();
        int max = 0;
        
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
        
        for (size_t i = 1; i < len1 + 1; i++)
        {
            for (size_t j = 1; j < len2 + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        
        std::cout << max << std::endl;
    }
    
    return 0;
}