class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> umap;
        
        int begin = 0;
        int end = 0;
        
        do
        {
            end = A.find(' ', begin);
            
            string tmp = A.substr(begin, end - begin);
            umap[tmp]++;
            
            begin = end + 1;
            
        } while (end != -1);
            
        begin = 0;
        do
        {
            end = B.find(' ', begin);
            
            string tmp = B.substr(begin, end - begin);
            umap[tmp]++;
            
            begin = end + 1;
            
        } while (end != -1);    
        
        vector<string> ans;
        for (const auto& e : umap)
        {
            if (e.second == 1)
                ans.push_back(e.first);
        }
        
        return ans;
    }
};