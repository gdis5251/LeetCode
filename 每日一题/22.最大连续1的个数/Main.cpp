#include <iostream>

int GetNumberOfContinuous1(int n)
{
    int max = 0;
    int sum = 0;
    
    while (n != 0)
    {
        if ((n & 1) == 1)
            sum++;
        else
        {
            if (sum > max)
                max = sum;
            sum = 0;
            
        }
        
        n >>= 1;
    }
    if (sum > max)
        max = sum;
    
    return max;
}

int main(void)
{
    int input;
    while (std::cin >> input)
    {
        int ans = GetNumberOfContinuous1(input);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}