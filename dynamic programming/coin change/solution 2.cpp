class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX-1));
        
        for(int i=1; i<=n; ++i)
            for(int j=0; j<=amount; ++j){
                if(j==0) dp[i][j]=0;
                else if(j<coins[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
            }
        
        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
}