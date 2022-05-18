// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        
        bool *visited = new bool[n];
        
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        
        vector<int> ans;
        queue<int> pending_vertices;
        
        pending_vertices.push(0);
        visited[0]=true;
        while(pending_vertices.size()!=0){
            int frontVertice = pending_vertices.front();
            pending_vertices.pop();
            ans.push_back(frontVertice);
            for(auto i:adj[frontVertice])
            {
                if(i==frontVertice)
                continue;
                
                if(visited[i])
                continue;
                
                pending_vertices.push(i);
                visited[i]=true;
            }
            
        }
        return ans;
    }   
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends