#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(std::vector<int>& arr, int len) {
        int i = 0;
        int j = 1;
        
        while (i < len && j < len)
        {
            while (i % 2 == 0 && arr[i] % 2 == 0)
            {
                i += 2;
            }
            while (j % 2 != 0 && arr[j] % 2 != 0)
            {
                j += 2;
            }
            
            std::swap(arr[i], arr[j]);
        }
    }
};

int main(void)
{
    std::vector<int> arr{7,7,9,5,1,6,7,9,3,2,6};
    Solution s;
    s.oddInOddEvenInEven(arr, arr.size());

    for (const auto& e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}