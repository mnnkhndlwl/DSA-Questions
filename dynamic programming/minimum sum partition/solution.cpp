// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = 0;
	    for(int i = 0;i<n;i++)
	    {
	        range+=arr[i];
	    }
	    
	    vector<int> v;
	    
	    solve(arr,range,n,v);
	    
	    int apna_ans = INT_MAX;
	    
	    for(int i = 0;i<v.size();i++)
	    {
	        apna_ans = min(apna_ans,range-(2*v[i]));
	    }
	    return apna_ans;
	} 
	// same subset sum ki tarah
	int solve(int arr[], int sum , int n ,vector<int> &v)
	{
	    int t[n+1][sum+1];
	    //initialisation
	    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
               t[i][j]=1;
        }
	}
	
	for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
           if(arr[i-1]<=j){
               t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j];
           }else{
               t[i][j]=t[i-1][j];
           }
        }
    }
    
    for(int j = 0 ;j<=sum/2;j++)
    {
        if(t[n][j] == 1)
        v.push_back(j);
    }
	
	
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends