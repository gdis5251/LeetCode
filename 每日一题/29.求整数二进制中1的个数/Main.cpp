#include <iostream>

int Solution(int num)
{
    int count = 0;
    
    int i = 1;
    i <<= 31;
    
    while (num != 0)
    {
        if ((num & i) != 0)
            count++;
        
        num <<= 1;
    }
    
    return count;
}

int main(void)
{
    int num = 0;
    while (std::cin >> num)
    {
        int ans = Solution(num);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}