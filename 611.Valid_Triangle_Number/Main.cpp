#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    static int triangleNumber(std::vector<int>& nums) {
        if (nums.size() < 3)
           return 0;
           
        sort(nums.begin(), nums.end());
        size_t count = 0;
        
        for (size_t i = nums.size() - 1; i >= 2; i--)
        {
            size_t k = 0;
            size_t j = i - 1;
            while (k < j)
            {
            if (nums[j] + nums[k] > nums[i])
            {    
            count += j - k;
                j--;
                                                
            }
            else
                k++;
                        
            }
                    
        }
               
        return count;
                    
    }
    
};

int main(void)
{
    int array[] = { 2, 2, 3, 4 };
    std::vector<int> nums(array, array + sizeof(array) / sizeof(int));

    int res = Solution::triangleNumber(nums);
    std::cout << res << std::endl;

    return 0;
}
