// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int x, int y, string current_path, vector<vector<int>> visited, vector<string> &ans, vector<vector<int>> m, int n){
         if(x < 0 || x == n || y < 0 || y == n || m[x][y] == 0 ||  visited[x][y] == 1){
            return;
        }
        
        if(x == n-1 && y == n-1){
            if(m[x][y] != 0){
                ans.push_back(current_path);
            }
            return;
        }
        
       
        
        visited[x][y] = 1;
        dfs(x-1,y,current_path + "U",visited,ans,m,n);
        dfs(x,y-1,current_path + "L",visited,ans,m,n);
        dfs(x+1,y,current_path + "D",visited,ans,m,n);
        dfs(x,y+1,current_path + "R",visited,ans,m,n);
        visited[x][y] = 0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                visited[i].push_back(0);
            }
        }
        
        vector<string> ans;
        
        dfs(0,0,"",visited,ans,m,n);
        
        return ans;
    }
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends