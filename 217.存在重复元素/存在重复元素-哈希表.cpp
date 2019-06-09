class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        for (const auto& e : nums)
        {
            umap[e]++;
        }
        
        for (const auto& e : umap)
        {
            if (e.second >= 2)
                return true;
        }
        
        return false;
    }
};