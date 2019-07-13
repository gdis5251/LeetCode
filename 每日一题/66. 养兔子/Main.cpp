// write your code here cpp
#include <iostream>

long long GetRabbitNum(int n)
{
    if (1 == n)
    {
        return 1;
    }
    else if (2 == n)
    {
        return 2;
    }
    
    long long first = 1;
    long long second = 2;
    long long ans = 0;
    
    for (int i = 3; i <= n; i++)
    {
        ans = first + second;
        first = second;
        second = ans;
    }
    
    return ans;
}

int main(void)
{
    int n = 0;
    
    while (std::cin >> n)
    {
        long long ans = GetRabbitNum(n);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}