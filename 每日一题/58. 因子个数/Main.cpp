// write your code here cpp
#include <iostream>
#include <cmath>

int GetDivisorNum(int n)
{
    int count = 0;
    int num = n;
    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            count++;
        }
    }
    
    if (n != 1)
    {
        count++;
    }
    
    return count;
}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        int ans = GetDivisorNum(n);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}