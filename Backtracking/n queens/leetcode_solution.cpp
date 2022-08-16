lass Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string>curr(n,str);
        vector<vector<string>> res;
        addWays(res,curr,n,0);
        return res;
    }
    bool addWays(vector<vector<string>> &res, vector<string> &curr, int n, int i){
        if(i == n){
            res.push_back(curr);
            return false;
        }
        for(int j = 0;j<n;j++){
            if(canPlace(curr,n,i,j))
            {
                 curr[i][j] = 'Q';
                bool success = addWays(res, curr, n , i+1);
                if(success){
                    return true;
                }
                
                //backtrack
                curr[i][j] = '.';
            }
        }
        return false;
    }
     bool canPlace(vector<string> curr, int n, int x, int y){
        for(int k = 0; k<x; k++){
            if(curr[k][y] == 'Q') return false;
        }
        
        //left diagonal check
        int i = x, j = y;
        while(i>=0 and j>=0){
            if(curr[i][j] == 'Q') return false;
            i--, j--;
        }
        
        //right diagonal check
        i = x, j = y;
        while(i>=0 and j<n){
            if(curr[i][j] == 'Q') return false;
            i--, j++;
        }
        
        return true;
    }
};