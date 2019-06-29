#include "Code.hpp"

int main(void)
{
    vector<int> arr{1, 1, -1, -1, 3}; 
    Solution s; 
    int ans = s.threeSumClosest(arr, -1);
   
    std::cout << ans << std::endl;

    return 0;
}