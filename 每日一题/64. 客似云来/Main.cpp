// write your code here cpp
#include <iostream>
#include <vector>

void GetFibArr(std::vector<long long>& arr)
{
    arr[1] = 1;
    arr[2] = 1;
    
    for (int i = 3; i <= 80; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main(void)
{
    int from = 0;
    int to = 0;
    
    std::vector<long long> fib(81);
    GetFibArr(fib);
    
    while (std::cin >> from >> to)
    {
        long long ans = 0;
        
        for (int i = from; i <= to; i++)
        {
            ans += fib[i];
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}