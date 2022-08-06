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

// Count Good pairs instead of Bad pairs
// Ans = Total pairs - No of Good pairs
// Number of total pairs where i<j = (n*(n-1))/2

// A pair is said to be good if i < j and j - i == nums[j] - nums[i]
// This can be rewritten as j - nums[j] == i- nums[i]

// Keep a track of this difference using a map

// If difference is found in future -
// It is a good pair, add its count to goodpair_count
// increment its count also in the map as well.