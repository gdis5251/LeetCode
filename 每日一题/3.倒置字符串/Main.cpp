#include <iostream>
#include <string>
#include <algorithm>

void ReverseWords(std::string& str)
{
    // 先将str整体倒置
    reverse(str.begin(), str.end());
    
    // 然后在对每个空格前的单词进行翻转
    std::string::iterator sit = str.begin();
    while (sit != str.end())
    {
        std::string::iterator send = std::find(sit, str.end(), ' ');
        // 如果没找到break
        if (send == str.end())
            break;
        
        // 翻转空格前的单词
        reverse(sit, send);
        
        // 更新迭代器
        sit = send + 1;
        send = str.end();
    }
    // 翻转最后一个单词
    reverse(sit, str.end());
}

int main(void)
{
    std::string str;
    while (std::getline(std::cin, str))
    {
        ReverseWords(str);
        
        std::cout << str << std::endl;
    }
    
    return 0;
}
