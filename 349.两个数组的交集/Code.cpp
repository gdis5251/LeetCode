class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1;
        unordered_set<int> uset2;

        
        for (const auto& e : nums1)
        {
            uset1.insert(e);
        }
        
        for (const auto& e : nums2)
        {
            uset2.insert(e);
        }
        
        vector<int> ans;
        for (const auto& e : uset1)
        {
            if (uset2.find(e) != uset2.end())
                ans.push_back(e);
        }
        
        return ans;
    }
};