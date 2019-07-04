// write your code here cpp
#include <iostream>


int main(void)
{
    long long n = 0;
    while (std::cin >> n)
    {
        if (n == 0)
            continue;
        int ans = 0;

        while (n >= 2)
        {
            if (n % 3 != 0)
            {
                n = n / 3 + 1;
            }
            else
            {
                n /= 3;
            }
            ans++;
        }
        std::cout << ans << std::endl;
    }
    
    return 0;
}