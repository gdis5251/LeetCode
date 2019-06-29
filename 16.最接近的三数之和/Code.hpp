#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        
        int ans;
        int min = INT_MAX;
        
        // 大循环上遍历一遍数组
        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            // 用两个下标，分别从当前的一左一右开始找
            // 找到符合条件的就插入到数组里
            int left = i + 1;
            int right = (int)nums.size() - 1;
            
            // 如果当前的值跟上一次的值重复了，就跳过
            if (i > 0 && nums[i] == nums[i - 1])
            {
             // continue;
            }
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == target)
                {
                    return sum;   
                }
                else if (sum > target)
                {
                    right--;

                    if (abs(sum - target) < min)
                    {
                        min = abs(sum - target);
                        ans = sum;
                    }
                    
                }
                else
                {
                    left++;

                    if (abs(sum - target) < min)
                    {
                        min = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }
        
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = threeSum(nums, target);
        
        return ans;
    }
};