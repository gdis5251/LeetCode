#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int FindGreatestSumOfSubArray(vector<int> array) {
        int max = -INT_MAX;
        int sum = 0;
                                
        for (size_t i = 0; i < array.size(); i++)
        {
            sum = 0;
            for (size_t j = i; j < array.size(); j++)
            {
                sum += array[j];
                if (sum > max)
                max = sum;
                                        
            }
                 
        }
                
        return max;
                    
    }
    
};

int main(void)
{
    vector<int> array;
    array.push_back(6);
    array.push_back(-3);
    array.push_back(-2);
    array.push_back(7);
    array.push_back(-15);
    array.push_back(1);
    array.push_back(2);
    array.push_back(2);
    int max = Solution::FindGreatestSumOfSubArray(array);

    std::cout << max << std::endl;

    return 0;
}






