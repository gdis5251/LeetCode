#include <iostream>
#include <vector>

int GetDivisor(int a, int b)
{
    if (a % b != 0)
    {
        b = GetDivisor(b, a % b);
    }
    
    return b;
}

int main(void)
{
    int num = 0;
    int init_power = 0;
    
    while (std::cin >> num >> init_power)
    {
        std::vector<int> monsters_power(num);
        for (int i = 0; i < num; i++)
        {
            std::cin >> monsters_power[i];
        }
        
        for (size_t j = 0; j < monsters_power.size(); j++)
        {
            if (init_power >= monsters_power[j])
            {
                init_power += monsters_power[j];
            }
            else
            {
                init_power += GetDivisor(init_power, monsters_power[j]);
            }
        }
        
        std::cout << init_power << std::endl;
    }
    
    return 0;
}