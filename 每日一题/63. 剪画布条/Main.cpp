// write your code here cpp
#include <iostream>
#include <string>

int GetSubstr(const std::string& lhs, const std::string& rhs)
{
    size_t pos = 0;
    size_t len = 0;
    int count = 0;
    while ((len = lhs.find(rhs, 0 + pos)) != -1)
    {
        count++;
        pos = len + rhs.size();
    }
    
    return count;
}

int main(void)
{
    std::string big_str;
    std::string sm_str;
    
    while (std::cin >> big_str >> sm_str)
    {
        int ans = GetSubstr(big_str, sm_str);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}