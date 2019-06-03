#include <iostream>
#include <math.h>
#include <limits.h>

bool JudgeIsPrime(int x)
{
    for(int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    
    return true;
    
}

void DoCompete(int num)
{
    int half = num / 2;
    int i;
    for (i = half; i > 0; i--)
    {
        if (JudgeIsPrime(i) && JudgeIsPrime(num - i))
        {
            break;
        }
    }
     
    std::cout << i  << std::endl;
    std::cout << num - i  << std::endl;
    
}

int main(void)
{
    int num = 0;
    while (std::cin >> num)
    {
        DoCompete(num);
    }
    
    return 0;
}
