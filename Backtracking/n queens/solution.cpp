// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row,int col,vector<string>& ans,int n)
    {
        int origrow=row;
        int origcol=col;
        while(row>=0 && col>=0)
        {
            if(ans[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=origrow;
        col=origcol;
        while(col>=0)
        {
           if(ans[row][col]=='Q')return false;
                col--; 
        }
        row=origrow;
        col=origcol;
        while(row<n && col>=0)
        {
            if(ans[row][col]=='Q')return false;
                row++;
                col--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<string>>& ans,vector<string>& temp)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int row =0;row<n;row++)
        {
            if(isSafe(row,col,temp,n))
            {
                temp[row][col]='Q';
                solve(col+1,n,ans,temp);
                temp[row][col]='-';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string local(n,'-');
        for(int i=0;i<n;i++)
            temp[i]=local;
        solve(0,n,ans,temp);
        vector<string> loc;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                string str=ans[i][j];
                loc.push_back(str);
                // cout<<str<<endl;
            }
            // cout<<endl;
        }
        vector<vector<int>> ans1;
        for(int i=0;i<ans.size();i++)
        {
            vector<int> temp1;
            for(int j=0;j<ans[i].size();j++)
            {
                string str=ans[i][j];
                for(int k=0;k<str.size();k++)
                {
                    if(str[k]=='Q')
                        temp1.push_back(k+1); 
                }
            }
            ans1.push_back(temp1);
        }
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends