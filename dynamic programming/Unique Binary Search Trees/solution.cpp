class Solution {
    private:
    vector<int>memo;
public:
    int numTrees(int n)
    {
     memo.resize(n+1,-1);
       return fun(n);
    }
    int fun(int n)
    {
        // Base Case
           if(n==0)
               return 1;
        
        // Dp Condition
        if(memo[n]!=-1)
            return memo[n];
        
        int result=0;
          for(int i=0;i<n;i++)
              result+=(fun(i)*fun(n-1-i));
        return memo[n]=result;
    }
};