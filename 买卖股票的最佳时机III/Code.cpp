class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MIN;
        int first_sell = 0;
        int second_buy = INT_MIN;
        int second_sell = 0;
        
        for (size_t i = 0; i < prices.size(); i++)
        {
            first_buy = max(first_buy, -prices[i]);
            first_sell = max(first_sell, first_buy + prices[i]);
            second_buy = max(second_buy, first_sell - prices[i]);
            second_sell = max(second_sell, second_buy + prices[i]);
        }
        
        return second_sell;
    }
};