 class Solution {
public:
    
    // direction co-ordinates for left, right, top, bottom
    
    vector<int> dx = {-1, 0, 1, 0};
    
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& height, int i, int j, int n, int m, int prev, vector<vector<bool>>& vis)
    {
        // base case
        
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || height[i][j] < prev)
            return;
        
        // mark the curr cell as visited
        
        vis[i][j] = true;
        
        // move in all 4 directions
        
        for(int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];
            
            int new_j = j + dy[k];
            
            dfs(height, new_i, new_j, n, m, height[i][j], vis);
        }
    }
  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        
        int m = heights[0].size();
        
        // pacific[i][j] will store can we reach to the pacific ocean
        
        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        
        // we know one thing is that we can always reach to pacific ocean from 1st col and 1st row
        
        // so start dfs traversal from 1st row and 1st col and check from which cell we can reach the pacific ocean
        
        // start dfs from 1st col
        
        for(int i = 0; i < n; i++)
        {
            dfs(heights, i, 0, n, m, heights[i][0], pacific);
        }
        
        // dfs from 1st row
        
        for(int j = 0; j < m; j++)
        {
            dfs(heights, 0, j, n, m, heights[0][j], pacific);
        }
        
        // atlantic[i][j] will store can we reach to the atlantic ocean
        
        vector<vector<bool>> atlantic(n, vector<bool> (m, false));
        
        // we know one thing is that we can always reach to atlantic ocean from last col and last row
        
        // so start dfs traversal from last row and last col and check from which cell we can reach the pacific ocean 
        
        // dfs from last col
        
        for(int i = 0; i < n; i++)
        {
            dfs(heights, i, m - 1, n, m, heights[i][m - 1], atlantic);
        }
        
        // dfs from last row
        
        for(int j = 0; j < m; j++)
        {
            dfs(heights, n - 1, j, n, m, heights[n - 1][j], atlantic);
        }
        
        // now check from which cell we can reach to the pacific as well as atlantic ocean
        
        // store the index no. of cell into res
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
      
        return res;
    }
};