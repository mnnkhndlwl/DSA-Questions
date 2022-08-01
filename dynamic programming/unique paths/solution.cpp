// Take some position eg: arr[5][5], We can come to position(5,5) from (4,5) and (5, 4)
// So if we sum both of them we can get value for (5,5).
// The robot can only move right and down, when we see at some point, it either comes from left or above. 
// If we use dp[i][j] for the present path to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j].  
// for present value we are using help of previous values.(dynamic programming)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2d vector for m*n and set value to 1;
		
        vector<vector<int>> dp(m, vector<int>(n, 1));
		
        // Many may confuse by seeing the above line 
        // This is same as dp[m][n] = {0} using array
        
        // iterate to all the grids in m*n and set dp[i][j] = dp[i-1][j] + dp[i][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // Finally result the last grid ans
        return dp[m - 1][n - 1];
        
    }
};