#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static int StrToInt(string str) {
        int is_minus = 0;
        auto sit = str.begin();
        int ans = 0;
        
        if (*sit == '-')
        {
            is_minus = 1;
            sit++;
        }
        else if (*sit == '+')
            sit++;
        
        while (*sit >= '0' && *sit <= '9' && sit != str.end())
        {
            ans *= 10;
            ans += *sit - '0';
            sit++;
            
            if (!(*sit >= '0' && *sit <= '9') && sit != str.end())
            {
                return 0;
            }
        }
        
        if (is_minus == 1)
            ans = -ans;
        
        return ans;
    }
};

int main(void)
{
    int ans = Solution::StrToInt("+2147483647");
    std::cout << ans << std::endl;

    return 0;
}
