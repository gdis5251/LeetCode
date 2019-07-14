#include <iostream>
#include <vector>

void PrintSum(int n, int m, std::vector<int>& v, int beg)
{
    if (0 == m)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            i == 0 ? std::cout << v[i] : std::cout << " " << v[i];
        }
        std::cout << std::endl;
    }
    
    for (int i = beg; i <= n && i <= m; i++)
    {
        v.push_back(i);
        PrintSum(n, m - i, v, i + 1);
        v.pop_back();
    }
}

int main(void)
{
    int n = 0;
    int m = 0;
    
    while (std::cin >> n >> m)
    {
        std::vector<int> v;
        PrintSum(n, m, v, 1);
    }
    
    return 0;
}