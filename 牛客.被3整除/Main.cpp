#include <iostream>

int main(void)
{
    int count = 0;
    int sum = 0;
    int l = 0;
    int r = 0;

    while (std::cin >> l >> r)
    {
        // 主要思路就是计算每一位的和，能否被3整除即可
        for (int i = 1; i <= r; i++)
        {
            if (i < l)
            {
                sum += i % 10;

            }
            else
            {
                sum += i % 10;
                if (sum % 3 == 0)
                {
                    count++;

                }

            }

        }

        std::cout << count << std::endl;

    }


    return 0;

}
