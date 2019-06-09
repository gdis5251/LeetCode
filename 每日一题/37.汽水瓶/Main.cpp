#include <iostream>
#include <vector>

int GetBottle(int n)
{
    int ans = n / 3;
    int left = (n % 3) + ans;;
    
    while (left >= 3)
    {
        int bottle = 0;
        bottle = left / 3;
        
        left %= 3;
        left += bottle;
        
        ans += bottle;
    }
    
    if (left == 2)
        ans += 1;
    
    return ans;
}

int main(void)
{
    while (true)
    {
        int num = 0;
        std::cin >> num;
        if (num == 0)
            break;
          
        int ans = GetBottle(num);
        std::cout << ans << std::endl;
    }
    
    return 0;
}
