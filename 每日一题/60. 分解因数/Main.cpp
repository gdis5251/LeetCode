// write your code here cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

void PrimeNumber(int num, std::unordered_set<int>& hash)
{
    for (int i = 2; i <= num / 2; i++)
    {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            hash.insert(i);
        }
    }
}

void PrintDivisor(int num)
{
    std::unordered_set<int> hash;
    PrimeNumber(num, hash);
    std::cout << num << " = ";

    int count = 0;
    
    int n = num;
    bool flag = false;
    
    for (int i = 2; i <= num / 2 && n != 1; i++)
    {
        while (hash.find(i) != hash.end() && n % i == 0 && n != 1)
        {
            if (count++ != 0)
                std::cout << "* ";
            n /= i;
            std::cout << i << " ";
            flag = true;
        }
    }
    
    if (!flag)
    {
        std::cout << 1 << " * " << num << std::endl;
    }
    else
    {
        std::cout << std::endl;
    }
}

int main(void)
{
    int num = 0;
    
    while (std::cin >> num)
    {
        PrintDivisor(num);
    }
    
    return 0;
}