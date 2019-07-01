#include <iostream>

const double PI = 3.14;

int main(void)
{
    long double cat_length = 0;
    long double r = 0;
    
    while (std::cin >> cat_length >> r)
    {
        long double l = 2 * PI * r;
        if (cat_length > l)
        {
            std::cout << "No" << std::endl;
        }
        else
        {
            std::cout << "Yes" << std::endl;
        }
    }
    return 0;
}
