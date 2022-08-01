int Solution::maxProfit(const vector<int> &prices) {
    if(prices.size() == 0)
    {
        return 0;
    }
    int maxprofit = 0;
        int minsofar = prices[0];
        for(int i =0 ;i < prices.size();i++)
        {
            minsofar = min(minsofar,prices[i]);
            int profit = prices[i] - minsofar;
            maxprofit = max(profit,maxprofit);
        }
        if(maxprofit < 0)
        {
            return 0;
        }
        return maxprofit;
}