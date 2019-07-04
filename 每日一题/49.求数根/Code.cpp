// write your code here cpp、
#include <iostream>
#include <string>
#include <sstream>


int GetRootNum(const std::string& num)
{
    std::string tmp = num;
    bool is_continue = true;

    while (is_continue)
    {
        if (tmp.size() < 2)
        {
            return tmp[0] - '0';
        }
        else
        {
            std::stringstream ss;
            // 把 tmp 的每一位加起来,赋值给 tmp
            long long sum = 0;
            auto tit = tmp.rbegin();
            while (tit != tmp.rend())
            {
                sum += *tit - '0';
                tit++;
            }

            ss << sum;
            tmp = ss.str();
        }
    }

    return 0;
}

int main(void)
{
    std::string num;
    while (std::getline(std::cin, num))
    {
        int ans = GetRootNum(num);

        std::cout << ans << std::endl;
    }

    return 0;
}
