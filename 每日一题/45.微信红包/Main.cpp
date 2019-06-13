#include <unordered_map>
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        unordered_map<int, int> hash;
        for (const auto& e : gifts)
        {
            hash[e]++;
        }
        
        for (const auto& e : hash)
        {
            if (e.second >= (n / 2))
                return e.first;
        }
        
        return 0;
    }
};