// write your code here cpp
#include <iostream>
#include <cmath>

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        if (n == 0)
        {
            continue;
        }
        long a = pow(5, n);
        long b = pow(4, n);
        std::cout << a - 4 << " " << b + n - 4 << std::endl;
    }
    return 0;
}