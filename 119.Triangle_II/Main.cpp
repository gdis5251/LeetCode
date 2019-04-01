#include <vector>
#include <iostream>

class Solution {
public:
    static std::vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int> > nums;
        nums.resize(34);
                
        for (size_t i = 0; i < nums.size(); i++)
        {
            nums[i].resize(i + 1, 0);
                        
            nums[i][0] = 1;
            nums[i][nums[i].size() - 1] = 1;
                                            
        }
                
        for (size_t i = 2; i < nums.size(); i++)
        {
            for (size_t j = 1; j < i; j++)
            {
                nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];
            }
        }                
        return nums[rowIndex];
    }
};

int main(void)
{
    std::vector<int> res;
    int row = 0;
    std::cin >> row;

    res = Solution::getRow(row);

    std::vector<int>::iterator it = res.begin();
    while(it != res.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    return 0;
}
