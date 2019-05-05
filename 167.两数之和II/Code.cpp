class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        
        int i = 0;
        for (i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] > target)
                break;
        }
        
        if (i == 1)
            i++;
        
        for (size_t index1 = 0; index1 < i - 1; index1++)
        {
            for (size_t index2 = index1 + 1; index2 < i; index2++)
            {
                if (numbers[index1] + numbers[index2] == target)
                {
                    ans.push_back(index1 + 1);
                    ans.push_back(index2 + 1);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};