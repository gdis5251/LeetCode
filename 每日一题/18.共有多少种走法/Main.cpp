#include <iostream>
#include <vector>
// 本题需要使用深度优先搜索

int walk(int n, int m)
{
    if (n == 0 && m == 0)
        return 0;
    else if (n == 0 || m == 0)
        return 1;
    
    return walk(n - 1, m) + walk(n, m - 1);
}

int main(void)
{
    int n = 0;
    int m = 0;
    
    while (std::cin >> n >> m)
    {
        int ans = walk(n, m);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}