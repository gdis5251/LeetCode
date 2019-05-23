#include <iostream>
#include <string>

bool DetermineWhetherPalindrome(const std::string& str)
{
    if (str.empty())
        return true;
    
    auto sbegin = str.begin();
    auto send = str.end() - 1;
    
    while (sbegin < send)
    {
        if (*sbegin != *send)
            return false;
        
        sbegin++;
        send--;
    }
    
    return true;
}

int main(void)
{
    std::string str1;
    std::string str2;
    
    while (std::cin >> str1 >> str2)
    {
        size_t i = 0;
        int count = 0;
        
        for (i = 0; i <= str1.size(); i++)
        {
            str1.insert(i, str2);
            if (DetermineWhetherPalindrome(str1))
            {
                count++;
            }
            str1.erase(i, str2.size());
        }
        
        std::cout << count;
    }
    
    return 0;
}
