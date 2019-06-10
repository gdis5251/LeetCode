#include <iostream>
#include <string>

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void Reverse(std::string& str)
{
    std::string::iterator left = str.begin();
    std::string::iterator right = str.end() - 1;
    
    while (left < right)
    {
        swap(&(*left), &(*right));
        
        left++;
        right--;
    }
}

int main(void)
{
    std::string in_str;
    while (std::cin >> in_str)
    {
        Reverse(in_str);
        
        std::cout << in_str.c_str() << std::endl;
    }
    
    return 0;
}