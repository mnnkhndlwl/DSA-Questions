// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int n,vector<int>& arr,int sum,vector<vector<int>>& dp)
    {
         if(sum == 0) return true; //base case
       if(n == 0) return arr[0]==sum; // base case if n becomes 0 we need to check whether 
       // we reached the sum or not
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if(dp[n][sum] <= sum)
        {
            return dp[n][sum] = helper(n-1,arr,sum - arr[n],dp) || helper(n-1,arr,sum,dp);
        }
        else
        {
            return dp[n][sum] = helper(n-1,arr,sum,dp);
        }
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(n-1,arr,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 