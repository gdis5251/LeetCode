#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
    std::string in_str;
    while (std::getline(std::cin, in_str))
    {
        if (int pos = in_str.find("joker JOKER") != -1)
        {
            std::cout << "joker JOKER" << std::endl;
        }
        else
        {
            // 取出来两手牌
            int rpos = in_str.find('-');
            std::string card1 = in_str.substr(0, rpos);
            std::string card2 = in_str.substr(rpos + 1);
            
            // 计算两手牌各有多少张
            int count1 = std::count(card1.begin(), card1.end(), ' ');
            int count2 = std::count(card2.begin(), card2.end(), ' ');
            
            // 如果两手牌一样多，只需要比较最小的哪一张就好
            if (count1 == count2)
            {
                std::string first1 = card1.substr(0, card1.find(' '));
                std::string first2 = card2.substr(0, card2.find(' '));
                std::string str = "345678910JQKA2";
                
                if (str.find(first1.c_str()) > str.find(first2.c_str()))
                    std::cout << card1.c_str() << std::endl;
                else
                    std::cout << card2.c_str() << std::endl;
            }
            else
            {
                // 如果不一样多，那就是有一首牌里面有炸弹
                // 那么有炸弹的那副牌赢
                if (count1 == 3)
                    std::cout << card1.c_str() << std::endl;
                else if (count2 == 3)
                    std::cout << card2.c_str() << std::endl;
                else
                    std::cout << "ERROR" << std::endl;
            }
        }
    }
    
    return 0;
}