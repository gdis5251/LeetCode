class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        
        int max = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[max] < nums[i])
                max = i;
        }
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            
            if (max != i && nums[max] / nums[i] < 2)
                return -1;
        }
        
        return max;
    }
};