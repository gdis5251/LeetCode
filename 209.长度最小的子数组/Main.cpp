#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

/*
class Solution {
public:
    static int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int min = INT_MAX;
        int count = 0;
        int sum = 0;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i; j < nums.size(); j++)
            {
                if (sum < s)
                {
                    sum += nums[j];
                    count++;
                }
                else
                {
                    if (count < min)
                        min = count;
                    sum = 0;
                    count = 0;
                    break;
                }
            }
            if (sum >= s)
            {
                if (count < min)
                    min = count;
            }
            sum = 0;
            count = 0;
        }
        
        if (min == INT_MAX)
            return 0;
        
        return min;
    }
};
*/

//方法二：双指针法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s<=0||nums.size()==0) return 0;
        int i=0,j=0,sum=0,minL=INT_MAX;
        for (;j<nums.size();j++)
        {
            sum+=nums[j];
            while (sum>=s)
            {
                minL=min(minL,j-i+1);
                sum-=nums[i++];
            }
        }
        if (minL==INT_MAX) return 0;
        return minL;
    }
};


int main(void)
{
    vector<int> nums = {1, 1};

    int ans = Solution::minSubArrayLen(3, nums);

    cout << ans << endl;
    return 0;
}
