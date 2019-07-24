#include <iostream>

int main(void)
{
    long long arr[21] = {0, 0, 1};
    for (int i = 3; i < 21; i++)
    {
        arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);

    }

    int n = 0;
    while (std::cin >> n)
    {
        std::cout << arr[n] << std::endl;

    }

    return 0;

}
