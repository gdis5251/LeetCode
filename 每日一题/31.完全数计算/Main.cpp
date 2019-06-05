#include <iostream>
#include <cmath>

int Count(int num)
{
    int ans = 0;
    int sum = 0;
    for (int n = 2; n <= num; n++)
    {
        sum = 1;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                sum += i;
                if (n / i != i)
                {
                    sum += (n / i);
                }
            }
        
            if (sum > n)
                break;
        }
        
        if (sum == n)
            ans++;
    }
    
    return ans;
}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        int ans = Count(n);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
