#include <iostream>
#include <vector>
#include <algorithm>

int GetSteps(int n)
{
    if (n >= 0 && n < 4)
        return 0;
    int prev = 2;
    int cur = 3;
    int next = 0;
    
    while (cur < n)
    {
        next = prev + cur;
        prev = cur;
        cur = next;
    }
    // 跳出循环表示cur > n
    int ans = std::min(cur - n, n - prev);
    
    return ans;
}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        int ans = GetSteps(n);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
