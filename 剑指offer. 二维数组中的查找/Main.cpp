#include <iostream>
#include <vector>

bool FindNumber(std::vector<std::vector<int> >& nums, int number)
{
    bool found = false;
    
    int row = 0;
    int col = nums[0].size() - 1;

    while (row < nums.size() && col >= 0)
    {
        if (nums[row][col] == number)
        {
            found = true;
            break;
        }
        else if (nums[row][col] > number)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return found;
}

int main(void)
{
    std::vector<std::vector<int> > nums = { {1, 2, 8, 9}, 
                                            {2, 4, 9, 12}, 
                                            {4, 7, 10, 13}, 
                                            {6, 8, 11, 15}};
    int number = 0;

    while (std::cin >> number)
    {
        bool ans = FindNumber(nums, number);
        
        std::cout << ans << std::endl;
    }
}