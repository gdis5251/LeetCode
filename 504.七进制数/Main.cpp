#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        int isneg = 0;

        if (num < 0)
        {
            num = num * -1;
            isneg = 1;
        } 
        
        while (num / 7)
        {
            ans += num % 7 + '0';
            num /= 7;
        }
        ans += num % 7 + '0';
        if (isneg)
            ans += '-';
                        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(void)
{
    Solution a;
    string ans = a.convertToBase7(-7);

    cout << ans.c_str() << endl;
    return 0;
}
