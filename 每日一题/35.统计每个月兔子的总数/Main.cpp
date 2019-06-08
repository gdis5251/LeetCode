#include <iostream>
#include <vector>

int GetTotalCount(int month)
{
    std::vector<int> rabbit;
    rabbit.push_back(1);
    
    for (int i = 1; i < month; i++)
    {
        size_t len = rabbit.size();
        for (size_t j = 0; j < len; j++)
        {
            if (rabbit[j] != 3)
            {
                rabbit[j]++;
            }
            if (rabbit[j] == 3)
            {
                rabbit.push_back(1);
            }
        }
    }
    
    return rabbit.size();
}

int main(void)
{
    int month = 0;
    
    while (std::cin >> month)
    {
        int ans = GetTotalCount(month);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
