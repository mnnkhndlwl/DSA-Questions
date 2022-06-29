// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solve(int n,int sum,int arr[])
   {
        if(n==0)           // base case
           return 0;
        if(sum==0)         // base case
           return 1;
           
           if(arr[n-1] <= sum)
           return solve(n-1,sum - arr[n-1],arr) or solve(n-1,sum,arr);
           else
           return solve(n-1,sum,arr);
   }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=arr[i]; // finding sum of array
        }
        
        if(sum%2==0) // if sum is even that means we can divide our array into two equal parts
        return solve(n,sum/2,arr); // now our problem becomes same as subset sum problem
        else
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends