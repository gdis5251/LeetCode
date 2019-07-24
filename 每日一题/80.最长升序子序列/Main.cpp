#include <iostream>
#include <vector>

int GetMaxSubStrLength(const std::vector<int>& lhs)
{
    std::vector<int> dp(lhs.size(), 1);
    int max = 1;

    for (int i = 1; i < (int)lhs.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lhs[i] > lhs[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);

            }
            max = std::max(max, dp[i]);

        }

    }

    return max;

}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        std::vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> height[i];

        }

        int ans = GetMaxSubStrLength(height);

        std::cout << ans << std::endl;

    }

    return 0;

}
