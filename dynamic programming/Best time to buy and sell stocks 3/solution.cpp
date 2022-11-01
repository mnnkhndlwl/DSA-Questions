class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //varitation of best time to buy and sell stock with atmost k transactions
        //first i will write the non-optimised approach
        //let dp[i][j] be the maximum profit we obtain on the jth day after doing atmost i transactions
        //so dp[i][j]=max(dp[i][j-1],price[j]- (Σprice[k]+dp[i-1][k]));
        //where k ranges from 0 to j-1
        int k=2;
        int n=prices.size();
        int dp[k+1][n];
       /* for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    for(int k=0;k<j;k++){
                        dp[i][j]=max(dp[i][j],prices[j]-prices[k]+dp[i-1][k]);
                    }        
                }
            }
        }
        return dp[k][n-1];
        */
        //now lets see the optimised version
        //price[j]-Σprice[k]+dp[i-1][k];
        //price[j]+Σdp[i-1][k]-price[k]
        //so basically when we are iterating over j, we can keep track of max of the second term in the formula,i.e dp[i-1][k]-price[k],at each step in some var say prev_diff
        //so it will be price[j]+max(prev_diff,dp[i-1][j-1]-price[j-1]);
        //where prev_diff is maximum of Σdp[i-1][p]-price[p],where p ranges from 0 to j-2
        
        for(int i=0;i<=k;i++){
            int prev_diff=INT_MIN;
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else{
                    prev_diff=max(prev_diff,dp[i-1][j-1]-prices[j-1]);
                    dp[i][j]=max(dp[i][j-1],prices[j]+prev_diff);
                }
            }
        }
        return dp[k][n-1];
        
    }
};