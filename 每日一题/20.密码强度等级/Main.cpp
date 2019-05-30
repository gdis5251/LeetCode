#include <iostream>
#include <string>

int main(void)
{
    std::string pw;
    while (std::cin >> pw)
    {
        int sum = 0;
        
        // 先判断长度得分
        int length = pw.size();
        if (length <= 4)
            sum += 5;
        else if (length <= 7)
            sum += 10;
        else 
            sum += 25;
        
        // 字母得分
        int maj = 0;
        int min = 0;
        int count = 0;
        int ncount = 0;
        int ccount = 0;
        std::string::iterator pit = pw.begin();
        
        while (pit != pw.end())
        {
            if (*pit >= 'A' && *pit <= 'Z')
            {
                count++;
                maj++;
            }
            else if (*pit >= 'a' && *pit <= 'z')
            {
                count++;
                min++;
            }
            else if (*pit >= '0' && *pit <= '9')
                ncount++;
            else if ((*pit < '0' || *pit > '9') && (*pit < 'A' || *pit > 'Z') && (*pit < 'a' || *pit > 'z'))
                ccount++;
            
            pit++;
        }
        
        // 字母得分
        if ((min == 0 && maj != 0) || (min != 0 && maj == 0))
            sum += 10;
        else if (min != 0 && maj != 0)
            sum += 20;
        
        // 数字得分
        if (ncount == 1)
            sum += 10;
        else if (ncount > 1)
            sum += 25;
        
        // 字符得分
        if (ccount == 1)
            sum += 10;
        else if (ccount > 1)
            sum += 25;
        
        // 奖励
        if (count != 0 && ncount != 0 && ccount == 0)
            sum += 2;
        else if (count != 0 && ncount != 0 && ccount != 0)
        {
            if (maj != 0 && min != 0)
                sum += 5;
            else 
                sum += 3;
        }
        
        
        // 输出
        if (sum < 25)
            std::cout << "VERY_WEAK" << std::endl;
        else if (sum < 50)
            std::cout << "WEAK" << std::endl;
        else if (sum < 60)
            std::cout << "AVERAGE" << std::endl;
        else if (sum < 70)
            std::cout << "STRONG" << std::endl;
        else if (sum < 80)
            std::cout << "VERY_STRONG" << std::endl;
        else if (sum < 90)
            std::cout << "SECURE" << std::endl;
        else
            std::cout << "VERY_SECURE" << std::endl;
    }
    
    return 0;
}
