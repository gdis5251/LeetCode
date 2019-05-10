#include <iostream>


class Solution {
public:
    static bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        if ((num & (num - 1)) != 0)
            return false;
        if ((num & 0x55555555) == num)
            return true;
        
        return false;
    }
};
 
int main(void)
{
    Solution::isPowerOfFour(16);

    return 0;
}
