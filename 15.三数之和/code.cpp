class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<std::vector<int> > ans;
        
        // 大循环上遍历一遍数组
        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            // 用两个下标，分别从当前的一左一右开始找
            // 找到符合条件的就插入到数组里
            int left = i + 1;
            int right = (int)nums.size() - 1;
            
            // 如果 nums[i] > 0，则必然不可能三数相加等于0
            // 跳出
            if (nums[i] > 0)
            {
                break;
            }
            
            // 如果当前的值跟上一次的值重复了，就跳过
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    std::vector<int> tmp{nums[i], nums[left], nums[right]};
                    ans.push_back(tmp);
                
                    // 将后续与 left 或 right 下标值相同的结点跳过
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else 
                {
                    left++;
                }
            }
        }
        
        return ans;
    }
};