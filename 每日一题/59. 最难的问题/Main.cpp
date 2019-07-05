// write your code here cpp
#include <iostream>
#include <string>

void Exchange(std::string& str)
{
    auto sit = str.begin();
    
    while (sit != str.end())
    {
        if (*sit == ' ')
        {
        }
        else if (*sit > 'E')
        {
            *sit -= 5;
        }
        else
        {
            int distance = *sit - 'A';
            *sit = 'Z' - (5 - distance - 1);
        }
        sit++;
    }
}

int main(void)
{
    std::string input;
    
    while (std::getline(std::cin, input))
    {
        Exchange(input);
        
        std::cout << input.c_str() << std::endl;
    }
    
    return 0;
}