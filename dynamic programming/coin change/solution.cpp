class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for(int coin : coins)
                if(i >= coin && dp[i-coin] != -1)
                    dp[i] = min(dp[i], 1 + dp[i-coin]); 
            if(dp[i] == INT_MAX) dp[i] = -1;
        }
        return dp[amount];
    }
};