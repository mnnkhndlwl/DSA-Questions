class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            int x=nums[i]-i;
            if(mp.find(x)!=mp.end()) ans=ans+mp[x];
            mp[x]++;
        }
        long long cnt=n;
        cnt=(cnt*(n-1))/2;
        return cnt-ans;
    }
};