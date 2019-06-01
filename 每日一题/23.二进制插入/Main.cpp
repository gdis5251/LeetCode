#include <iostream>


class BinInsert {
public:
    static int binInsert(int n, int m, int j, int i) {
        // write code here
        int tmp = 0;
        int yu = 1;
        // 先把m的 i - j 位数，给tmp
        for (int k = 0; k <= i - j; k++)
        {
            if ((m & yu) != 0)
            {
                tmp |= yu;
            }
            yu <<= 1;
        }
        
        tmp <<= j;
        
        return n | tmp;
    }
};

int main(void)
{
    int ans = BinInsert::binInsert(1024, 19, 2, 6);
    std::cout << ans << std::endl;

    return 0;
}
