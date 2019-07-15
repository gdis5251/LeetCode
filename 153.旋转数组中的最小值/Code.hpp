class Solution {
public:
    int findMin(vector<int>& nums) {
        int lidx = 0;
        int ridx = nums.size() - 1;
        int midx = lidx;
        
        while (nums[lidx] >= nums[ridx])
        {
            if (1 == ridx - lidx)
            {
                midx = ridx;
                break;
            }
            
            midx = (lidx + ridx) / 2;
            
            if (nums[lidx] == nums[ridx] &&
               nums[lidx] == nums[midx])
            {
                return FindMin(nums, lidx, ridx);
            }
            
            if (nums[midx] > nums[lidx])
            {
                lidx = midx;
            }
            if (nums[midx] < nums[ridx])
            {
                ridx = midx;
            }
        }
        
        return nums[midx];
    }
    
private:
    static int FindMin(std::vector<int>& nums, int left, int right)
    {
        int ret = nums[left];
        for (int i = left + 1; i <= right; i++)
        {
            if (nums[i] < ret)
            {
                ret = nums[i];
            }
        }
        
        return ret;
    }
};