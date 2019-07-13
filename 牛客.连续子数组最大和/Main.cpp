#include <iostream>
#include <vector>

int GetMaxSum(std::vector<int>& arr)
{
    if (0 == arr.size())
    {
        return 0;
    }
    
    if (1 == arr.size())
    {
        return arr[0];
    }
    
    std::vector<int> dp(arr.size());
    dp[0] = arr[0];
    int max_sum = arr[0];
    
    for (int i = 1; i < arr.size(); i++)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + arr[i];
        }
        else
        {
            dp[i] = arr[i];
        }
        
        max_sum = max_sum > dp[i] ? max_sum : dp[i];
    }
    
    return max_sum;
        
}

int main(void)
{
    int n = 0;
    
    while (std::cin >> n)
    {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        
        int ans = GetMaxSum(arr);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}