#include <iostream>
#include <string>
#include <vector>
#include <cstring>


int main(void)
{
    size_t n = 0;
    std::vector<std::string> strs;// 先确定数据结构为字符串数组
    while (std::cin >> n)
    {
        int is_dictionary = 1;
        int is_length = 1;
        strs.clear();
        strs.resize(n);
        getchar();
        
        // 给字符串数组赋值
        for (size_t i = 0; i < n; i++)
        {
            std::getline(std::cin, strs[i]);
        }
        
        // 先判断是否是根据长度排序的
        for (size_t i = 1; i < n; i++)
        {
            if (strs[i - 1].size() > strs[i].size())
            {
                is_length = 0;
                break;
            }
        }
        
        // 判断是否是根据词典排序
        for (size_t i = 1; i < n; i++)
        {
            if (strcmp(strs[i - 1].c_str(), strs[i].c_str()) > 0)
            {
                is_dictionary = 0;
                break;
            }
        }
        
        if (is_dictionary == 1 && is_length == 1)
            std::cout << "both" << std::endl;
        else if(is_dictionary == 1)
            std::cout << "lexicographically" << std::endl;
        else if (is_length == 1)
            std::cout << "lengths" << std::endl;
        else
            std::cout << "none" << std::endl;
    }
    return 0;
}
