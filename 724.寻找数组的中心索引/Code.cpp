class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int leftSum = 0;
            int rightSum = 0;
            
            for (int l = i - 1; l >= 0; l--)
            {
                leftSum += nums[l];
            }
            
            for (int r = i + 1; r < nums.size(); r++)
            {
                rightSum += nums[r];
            }
            
            if (leftSum == rightSum)
                return i;
        }
        
        return -1;
    }
};
