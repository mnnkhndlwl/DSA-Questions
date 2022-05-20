// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool cycle(int n,int p,vector<int> &vis,vector<int>adj[])
    {
        vis[n]=1;
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                if(cycle(it, n ,vis, adj ))
          return true;
            }
            else if(it!=p)
            {
                return true;
            }
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,-1,vis,adj))
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends