class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unsigned long hash[1000000] = {0};
        for (size_t i = 0; i < numbers.size(); i++)
        {
            hash[numbers[i]]++;                                      
        }
                                
        for(size_t i = 0; i < numbers.size(); i++)
        {
            hash[numbers[i]] > (numbers.size() / 2))
            return numbers[i];
        }                                                
        return 0;
    }
};
