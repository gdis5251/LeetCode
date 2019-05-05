class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        vector<int>::const_iterator left = nums.begin();
        vector<int>::const_iterator right = nums.begin() + 2;
        
        sum += *left;
        while (right != nums.end())
        {
            left = right;
            right += 2;
            sum += *left;
        }
        
        return sum;
    }
};