class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        string s1;
        string s2;
        for(int i = 0;i<nums1.size();i++){
            s1+=nums1[i];
        }
        for(int i = 0;i<nums2.size();i++){
            s2+=nums2[i];
        }
        int ans = solution(s1,s2,s1.size(),s2.size());
        return ans;
    }
    int solution(string s1, string s2, int n, int m)
    {
       int dp[n+1][m+1],ans =0;
       memset(dp,0,sizeof(dp));
       for(int i =1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1])
               dp[i][j] = 1 + dp[i-1][j-1];
               else
               dp[i][j] = 0;
               ans = max(ans,dp[i][j]);
           }
       }
       return ans;
    }
};