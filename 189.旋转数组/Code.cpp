class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return;
        
        k = k % (int)nums.size();
        
        stack<int> s;
        for (int i = 0; i < k; i++)
        {
            s.push(nums[nums.size() - 1 - i]);
        }
        
        for (int i = 0; i < (int)nums.size() - k; i++)
        {
            nums[nums.size() - 1 - i] = nums[nums.size() - k - 1 - i];
        }
        
        for (int i = 0; i < k; i++)
        {
            nums[i] = s.top();
            s.pop();
        }
    }
};