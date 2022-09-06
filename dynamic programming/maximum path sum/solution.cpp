Recursive:

class Solution {
public:
    int solution(int i, int j, vector<vector<int>>&grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        
        int up = grid[i][j] + solution(i-1,j,grid);
        int left = grid[i][j] + solution(i,j-1,grid);
        
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        return solution(m-1,n-1,grid);
    }
};
Memoization:

class Solution {
public:
    int solution(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9; 
        }
        if(dp[i][j] != -1){ 
            return dp[i][j];
        }
        int up = grid[i][j] + solution(i-1,j,grid,dp);
        int left = grid[i][j] + solution(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return solution(m-1,n-1,grid,dp);
    }
};
Tabulation:

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up=1e9, left=1e9;
                    if(i>0){
                        up = grid[i][j] + dp[i-1][j];
                    }
                    if(j>0){
                        left = grid[i][j] + dp[i][j-1];
                    }
                    
                    dp[i][j] = min(up,left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};