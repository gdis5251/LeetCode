#include <iostream>
#include <string>

bool Judge(std::string& str1, std::string& str2)
{
    auto s1it = str1.begin();
    auto s2it = str2.begin();
    
    while (s1it != str1.end() && s2it != str2.end())
    {
        // 如果str1此时是 ？ 那就直接把问号被赋值
        if (*s1it == '?')
        {
            
        }
        else if (*s1it == '*')// 如果此时是 * 就让 str2 走到跟 * 的下一个字符匹配的位置
        {
            auto t1mp = s1it + 1;
            auto t2mp = s2it + 1;
            
            if (t1mp == str1.end())
                return true;
            else if (t2mp == str2.end())
                return false;
            
            while (*t1mp == '?' || *t1mp == '*')
                t1mp++;
                
            
            // 走到这里说明后面都有数据
            while (*t1mp != *t2mp && t1mp != str1.end() && t2mp != str2.end())
            {
                t2mp++;
            }
            
            // 如果此时 str2 走完了，可是 * 后面还有数据
            if (t2mp == str2.end())
                return false;
            
            s1it = t1mp;
            s2it = t2mp;
        }
        else
        {
            if (*s1it != *s2it)
                return false;
        }
        
        s1it++;
        s2it++;
    }
    
    return true;
}

int main(void)
{
    std::string str1;
    std::string str2;
    
    while (std::cin >> str1 >> str2)
    {
        bool ans = Judge(str1, str2);
        
        if (!ans)
            std::cout << "false" << std::endl;
        else
            std::cout << "true" << std::endl;
    }
    
    return 0;
}