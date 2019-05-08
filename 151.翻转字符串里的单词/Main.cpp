#include "Code.h"

int main(void)
{
    string s("the sky is blue");

    string ans = Solution::reverseWords(s);

    std::cout << ans.c_str() << std::endl;

    return 0;
}
