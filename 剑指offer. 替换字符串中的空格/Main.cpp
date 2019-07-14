#include <iostream>
#include <string>

void ReplaceBlank(std::string& str)
{
    std::string tmp;

    for (const auto& ch : str)
    {
        if (ch == ' ')
        {
            tmp += "%20";
        }
        else
        {
            tmp += ch;
        }
    }

    str.swap(tmp);
}

int main(void)
{
    std::string str = "we are happy";

    ReplaceBlank(str);

    std::cout << str.c_str() << std::endl;

    return 0;
}