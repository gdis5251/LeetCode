#include <iostream>
#include <string>

int main(void)
{
    std::string in_str;
    while (std::cin >> in_str)
    {
        int cur = 0;
        bool isPrint = true;
        
        for (; cur < in_str.size(); cur++)
        {
            int pos1 = in_str.find(in_str[cur], 0);
            int pos2 = in_str.find(in_str[cur], cur + 1);

            if (pos1 == cur && pos2 == -1)
            {
                std::cout << in_str[cur] << std::endl;
                isPrint = false;
                break;
            }
        }
        
        if (isPrint)
        {
            std::cout << -1 << std::endl;
        }
    }
    
    return 0;
}