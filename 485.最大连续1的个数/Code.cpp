class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int max = 0;
        int count = 0;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                if (count > max)
                    max = count;
            }
            else 
                count = 0;
        }
        
        return max;
    }
};