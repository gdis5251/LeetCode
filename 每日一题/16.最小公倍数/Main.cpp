#include <iostream>
#include <cmath>


int main(void)
{
    int a = 0;
    int b = 0;
    
    while (std::cin >> a >> b)
    {
        int mul = a * b;
        int tmp = mul - 1;
        
        while (tmp >= a && tmp >= b)
        {
            if (tmp % a == 0 && tmp % b == 0)
            {
                mul = tmp;
            }
            
            --tmp;
        }
        
        std::cout << mul << std::endl;
    }
    
    return 0;
}