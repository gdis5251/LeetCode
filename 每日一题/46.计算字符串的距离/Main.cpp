#include <iostream>
#include <string>
#include <vector>

int ComputerLength(std::string& a, std::string& b)
{
    int one = 0;
    int two = 0;
    int three = 0;
    std::vector<std::vector<int> > dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    
    for (size_t i = 1; i <= b.size(); i++)
    {
        dp[0][i] = i;
    }
    
    for (size_t i = 1; i <= a.size(); i++)
    {
        dp[i][0] = i;
    }
    dp[0][0] = 0;
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            one = dp[i - 1][j] + 1;
            two = dp[i][j - 1] + 1;
            three = dp[i - 1][j - 1];
            if (a[i - 1] != b[j - 1])
                three += 1;
            
            dp[i][j] = std::min(std::min(one, two), three);
        }
    }
    
    return dp[a.size()][b.size()];
}


int main(void)
{
    std::string a;
    std::string b;
    
    while (std::cin >> a >> b)
    {
        int ans = ComputerLength(a, b);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}