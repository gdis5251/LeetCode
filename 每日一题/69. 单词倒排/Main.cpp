#include <iostream>
#include <string>
#include <algorithm>

void ReverseRange(std::string& str, int left, int right)
{
    while (left < right)
    {
        std::swap(str[left++], str[right--]);
    }
}

void Reverse(std::string& str)
{
    if (str.size() == 0)
    {
        return;
    }
    // 先对每个单词进行逆序
    auto left = 0;
    auto right = str.size() - 1;
    volatile bool is_continue = true;
    
    while (is_continue)
    {
        // 双指针，找到空格，对两个指针之间的单词进行逆序
        right = str.find(' ', left);
        if (right != -1)
        {
            ReverseRange(str, left, right - 1);
        }
        else 
        {
            ReverseRange(str, left, (int)str.size() - 1);
            is_continue = false;
        }
        // 更新两个指针
        left = right + 1;
    }

    // 然后在对整个字符串进行整体逆序
    ReverseRange(str, 0, str.size() - 1);
}

void Filtrate(std::string& s)
{
    std::string str;
    
    // 去除尾部的特殊符号
    auto rsit = s.rbegin();
    while (rsit != s.rend())
    {
        if ((*rsit >= 65 && *rsit <= 90) || (*rsit >= 97 && *rsit <= 122))
        {
            break;
        }
        else
        {
            s.pop_back();
        }
        
        rsit++;
    }
    
    // 跳过头部特殊符号
    auto sit = s.begin();
    while (sit != s.end())
    {
        if ((*sit >= 65 && *sit <= 90) || (*sit >= 97 && *sit <= 122))
        {
            break;
        }
        else
        {
            sit++;
        }
    }
    
    // 赋值并除去中间的特殊符号
    while (sit != s.end())
    {
        if ((*sit >= 65 && *sit <= 90) || (*sit >= 97 && *sit <= 122))
        {
            str += *sit;
        }
        else
        {
            str += ' ';
        }
        
        sit++;
    }
    
    s.swap(str);
}

int main(void)
{
    std::string str;
    while (std::getline(std::cin, str))
    {
        Filtrate(str); 
        Reverse(str);
        
        std::cout << str.c_str() << std::endl;
    }
    
    return 0;
}