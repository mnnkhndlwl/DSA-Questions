class Solution {
public:

long long solve(int ind,vector<vector<int>>& arr,vector<long long> &dp)
{
    if(ind==arr.size()-1)
        return arr[arr.size()-1][0];
    
    if(ind>=arr.size())
        return 0;
    
    if(dp[ind]!=-1)
        return dp[ind];
    
    long long take=solve(ind+arr[ind][1]+1,arr,dp)+arr[ind][0];    //either incule the points in answer and jump to successive position as specified in the arr[ind][1]
    long long notTake=solve(ind+1,arr,dp);    //move to index+1 position without including the points in answer
    
    return dp[ind]=max(take,notTake);      //take maximum of both the choices
    
}

long long mostPoints(vector<vector<int>>& questions) {
    
    vector<long long> dp(questions.size(),-1);
    return solve(0,questions,dp);
    
}
};