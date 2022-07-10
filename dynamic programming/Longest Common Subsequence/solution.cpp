 class Solution {
public:
    int solve(string &s1, string &s2 ,int idx1 ,int idx2,vector<vector<int>>&dp){
        // base condition
        if(idx1<0|| idx2 <0)return 0;
        
        // check the cache
            if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        // if s1[idx]==s2[idx2]
        if(s1[idx1]==s2[idx2])
            return dp[idx1][idx2] = 1 + solve(s1,s2,idx1-1,idx2-1,dp);
        
        // if s1[idx1] != s2[idx2]
        return dp[idx1][idx2]= max( solve(s1,s2,idx1-1,idx2,dp) , solve(s1,s2,idx1,idx2-1,dp));
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s1,s2,n1-1,n2-1,dp);
    }
};