#include <iostream>
#include <string>

void ChangeNameStyle(std::string& str)
{
    // 创建一个跟新字符串
    std::string ans;
    // 循环遍历 str
    auto sit = str.begin();
    while (sit != str.end())
    {
        // 若当前字符是一个下划线：str 迭代器向后走一个，push_back （e - 32）
        if (*sit == '_')
        {
            ++sit;
            ans += *sit - 32;
        }
        // 若当前字符位一个普通字母：push_back
        else
        {
            ans += *sit;
        }
        
        sit++;
    }
    
    std::cout << ans.c_str() << std::endl;
}

int main(void)
{
    std::string str;
    while (std::cin >> str)
    {
        ChangeNameStyle(str);
    }
    
    return 0;
}