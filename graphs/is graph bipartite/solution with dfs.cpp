class Solution {
public:
    
    bool DFS(int cur, vector<vector<int>>&g, vector<int>&color) 
    {
        if(color[cur]==-1) color[cur] = 1;
        
        for(auto &nbr : g[cur])
        {
            if(color[nbr]==-1)
            {
                color[nbr] = 1-color[cur];
                if(DFS(nbr,g,color)==false)
                    return false;
            }
            else if(color[nbr] == color[cur])
                return false;
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
                if(DFS(i,g,color)==false){ // check for all the components of graph
                    return false;
                }
            }   
        }
        return true;
    }
};