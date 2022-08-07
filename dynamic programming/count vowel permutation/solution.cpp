class Solution {
public:
    // Mapping vowols to allowed Vowels
    // a -> e
    // e ->a,i
    // i !-> i
    // o -> i,u
    // u -> a
    
    int mod=1000000007;
     int dp[20001][26]={0};
    int solve(int idx,char prevchar,int n,map<char,vector<char>> &mp)
    {
        if(idx==n)return 1;
        if(dp[idx][prevchar-'a'])return dp[idx][prevchar-'a'];
         int t1=0;
       
       
        for(auto ch:mp[prevchar])
        {
            t1=(t1%mod+(solve(idx+1,ch,n,mp)%mod))%mod;
        }
    
    return dp[idx][prevchar-'a']=t1;
    }
    int countVowelPermutation(int n) {
        map<char,vector<char>> mp;
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        mp['s']={'a','e','i','o','u'};
     
        return solve(0,'s',n,mp);
        
        
    }
};