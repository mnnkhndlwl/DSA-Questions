// Simple Definition of Bipartite : 
// Acyclic - yes bipartite
// Cyclic - even length (yes bipartite)
// Cyclic - odd length (Not bipartite)
class Solution {
public:
    
    bool BFS(int i, vector<vector<int>>&g, vector<int>&color) 
    {
        int n=g.size(); // no. of nodes
        
        queue<int>q;
        q.push(i);
        
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            for(auto &nbr : g[cur])
            {
                if(color[nbr]==-1)
                {
                    color[nbr] = color[cur] ? 0 : 1;
                    q.push(nbr);
                }
                else if(color[nbr] == color[cur])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>&g) 
    {
        int n=g.size(); // no. of nodes
        vector<int>color(n,-1);
        
        // The graph may not be connected, meaning there may be two nodes u and v such that there 
        // is no path between them.
        for(int i=0;i<n;i++){
            
            if(color[i]==-1)
            {
                if(BFS(i,g,color)==false){ // check for all the components of graph
                    return false;
                }
            }   
        }
        return true;
    }
};