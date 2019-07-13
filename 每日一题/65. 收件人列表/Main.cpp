// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

void PrintList(std::vector<std::string>& name_list)
{
    for (size_t i = 0; i < name_list.size(); i++)
    {
        if (i != 0)
        {
            std::cout << ", ";
        }
        
        if (name_list[i].find(',') != -1 || 
            name_list[i].find(' ') != -1)
        {
            std::cout << '"' << name_list[i].c_str() << '"';
        }
        else
        {
            std::cout << name_list[i].c_str();
        }
    }
    std::cout << "\n";
}

int main(void)
{
    int n = 0;
    
    while (std::cin >> n)
    {
        // 接收回车
        getchar();
        // 获取收件人列表
        std::vector<std::string> name_list(n);
        for (int i = 0; i < n; i++)
        {
            std::getline(std::cin, name_list[i]);
        }
        
        PrintList(name_list);
    }
    
    return 0;
}