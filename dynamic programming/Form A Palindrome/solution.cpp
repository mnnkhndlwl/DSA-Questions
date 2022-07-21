 //{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    int n = str.size();
      string str1=str;
   reverse(str.begin(),str.end());
   int t[n+1][n+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
           if(i==0||j==0){
               t[i][j]=0;
           }
       }
   }
   
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(str[i-1]==str1[j-1]){
               t[i][j]=1+t[i-1][j-1];
           }
           else{
               t[i][j]=max(t[i-1][j],t[i][j-1]);
           }
       }
   }
   return n-t[n][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends