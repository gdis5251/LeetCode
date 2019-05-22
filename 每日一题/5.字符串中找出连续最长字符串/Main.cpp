#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    while (std::cin >> str)
    {
        std::string ans;
        
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                int mark = i; // 记录该位置
                int count = 0;
                size_t j = 0;
                
                for (j = i; j < str.size() && str[j] >= '0' && str[j] <= '9'; j++)
                {
                    count++;
                }
                
                if (count >= static_cast<int>(ans.size()))
                {
                    ans = str.substr(mark, count);
                }
                i = j;
            }
        }
            
        std::cout << ans.c_str() << std::endl;
    }
    return 0;
}
