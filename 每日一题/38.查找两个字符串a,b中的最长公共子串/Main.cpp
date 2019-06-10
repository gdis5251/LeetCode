#include <iostream>
#include <string>
#include <vector>

std::string GetLongestSubstr(std::string& str1, std::string& str2)
{
    if (str1.size() > str2.size())
    {
        str1.swap(str2);
    }
    
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    int max_len = 0;
    size_t start = 0;
    
    for (size_t i = 1; i < len1 + 1; i++)
    {
        for (size_t j = 1; j < len2 + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            
            if (dp[i][j] > max_len)
            {
                max_len = dp[i][j];
                start = (int)i - max_len;
            }
        }
    }
    
    return str1.substr(start, max_len);
}

int main(void)
{
    std::string str1;
    std::string str2;
    
    while (std::cin >> str1 >> str2)
    {
        std::string ans = GetLongestSubstr(str1, str2);
        
        std::cout << ans.c_str() << std::endl;
    }
    
    return 0;
}