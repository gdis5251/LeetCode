#include <iostream>

void Hnoi(int n, char a, char b, char c)
{
    // 这里思想很简单
    // 当 n == 1 只有一个盘，就把这一个盘，从 A 柱移动到 C 柱
    // 只要 n >= 1 假如有两个盘， 就把当前 A 柱上最上面的那个盘 从 A 柱先移到 B 柱
    // 再把 当前 A 柱上的那个盘 从 A 柱移动到 C 柱
    // 再把 B 柱当前的盘从 B 柱移动到 C 柱

    if (n == 1)
    {
        std::cout << "1: " << a << "->" << c << std::endl;
    }
    else
    {
        Hnoi(n - 1, a, c, b);
        std::cout << n << ": " << a << "->" << c << std::endl;
        Hnoi(n - 1, b, a, c);
    }
}

int main(void)
{
    int n = 0;
    char a = 'A';
    char b = 'B';
    char c = 'C';

    while (std::cin >> n)
    {
        Hnoi(n, a, b, c);
    }

    return 0;
}