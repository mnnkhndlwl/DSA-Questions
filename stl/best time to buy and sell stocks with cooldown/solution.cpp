class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_buy_0 = INT_MIN, max_sell_0 = 0, max_sell_1 = 0;
        for (int i = 0 ; i < prices.size(); ++i)
        {
            max_buy_0 = max(max_sell_1 - prices[i], max_buy_0);
            max_sell_1 = max_sell_0;
            max_sell_0 = max(max_sell_0, max_buy_0 + prices[i]);
        }
        return max_sell_0;
    }
};