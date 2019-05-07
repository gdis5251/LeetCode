class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (buy > prices[i])
            {
                buy = prices[i];
            }
            else if (profit < prices[i] - buy)
            {
                profit = prices[i] - buy;
            }
        }
        
        return profit;
    }
};