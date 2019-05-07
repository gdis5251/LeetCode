class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        
        int max_profit = 0;
        
        for (size_t i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
                max_profit += prices[i + 1] - prices[i];
        }
        
        return max_profit;
    }
};