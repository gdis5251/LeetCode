#include <iostream>
#include <string>

std::string GetNumber(const std::string& str)
{
    if (str.empty())
    {
        return "";

    }

    std::string ans;

    for (const auto& ch : str)
    {
        if (ch >= '0' && ch <= '9')
        {
            ans += ch;

        }

    }

    return ans;

}

int main(void)
{
    std::string input;
    while (std::getline(std::cin, input))
    {
        std::cout << GetNumber(input).c_str() << std::endl;

    }

    return 0;

}
