class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
        
        size_t i = 0;
        size_t next = 0;
        for (i = 0; i < nums.size() && next < nums.size(); i++)
        {
            next = i;
            if (nums[i] == 0)
            {
                while (next < nums.size() && nums[next] == 0)
                {
                    next++;
                }
                
                if (next < nums.size())
                    swap(nums[i], nums[next]);
            }
        }
    }
};