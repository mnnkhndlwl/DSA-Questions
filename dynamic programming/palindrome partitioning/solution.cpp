 class Solution{
    int t[501][501];
public:
bool isPali(string &A,int i,int j){
        while(i<j){
            if(A[i++]!=A[j--])return false;
        }
        return true;
    }
    int solve(string& str,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(t[i][j] != -1)
        {
            return t[i][j];
        }
        
        if(isPali(str,i,j))
        {
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int left,right;
            if(t[i][j] != -1)
            {
                left = t[i][k];
            }
            else{
                left = solve(str,i,k);
            }
            
            if(t[k+1][j] != -1)
            {
                right = t[k+1][j];
            }
            else{
                right = solve(str,k+1,j);
            }
            
            int temp_ans = left+right+1;
            ans = min(ans,temp_ans);
        }
        return t[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                t[i][j] = -1;
            }
        }
        int n = str.length();
        return solve(str,0,n-1);
    }
};