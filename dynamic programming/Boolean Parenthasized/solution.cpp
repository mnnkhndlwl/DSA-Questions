//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
       int solve(string& S, int i, int j, int flag, vector<vector<vector<int>>>& memo){
        // base cases
        if(i>j){
            return 0;
        }
        if(i == j){
            if(S[i] == 'T'){
                return 1 == flag;
            }
            else{
                return 0 == flag;
            }
        }
        if(memo[i][j][flag] != -1){
            return memo[i][j][flag];
        }
        
        int result = 0;
        
        // check every possibility, similar to matrix chain multiplication
        for(int k=i+1; k<j; k++){
            if(S[k]=='&' or S[k]=='|' or S[k]=='^'){
                // find the number of ways in which the left and right expression can be true or false
                int lT = solve(S, i, k-1, true, memo);
                int lF = solve(S, i, k-1, false, memo);
                int rT = solve(S, k+1, j, true, memo);
                int rF = solve(S, k+1, j, false, memo);
                
                // find the number of ways in which the expression can evaluate to true
                if(flag){
                    if(S[k] == '&'){
                        result += lT*rT;
                    }
                    else if(S[k] == '|'){
                        result += lT*rT + lF*rT + lT*rF;
                    }
                    else{
                        result += lF*rT + lT*rF;
                    }
                }
                // find the number of ways in which the expression can evaluate to false
                else{
                    if(S[k] == '&'){
                        result += lF*rT + lT*rF + lF*rF;
                    }
                    else if(S[k] == '|'){
                        result += lF*rF;
                    }
                    else{
                        result += lT*rT + lF*rF;
                    }
                }
            }
        }
        
        memo[i][j][flag] = result%1003;
        return memo[i][j][flag];
    }
    
    int countWays(int N, string S){
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return solve(S, 0, N-1, 1, memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends