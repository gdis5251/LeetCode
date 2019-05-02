class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;
        int jw = 0;
        
        for (int i = (int)digits.size() - 1; i >= 0; i--)
        {
            digits[i] += jw;
            if (digits[i] > 9)
            {
                digits[i] -= 10;
                jw = 1;
            }
            else 
                jw = 0;
            
            if (jw == 0)
                break;
        }
        
        if (jw != 0)
        {
            vector<int> ans;
            ans.resize(digits.size() + 1);
            ans[0] = 1;
            
            for (size_t i = 0; i < digits.size(); i++)
            {
                ans[i + 1] = digits[i];
            }
            return ans;
        }
        
        return digits;
    }
};