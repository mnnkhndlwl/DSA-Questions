class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        map<int,int> mp;
        int maxbeauty=INT_MIN;
        for(auto i:items){
            maxbeauty=max(maxbeauty,i[1]);
            mp[i[0]]=maxbeauty;
        }
        vector<int> ans(queries.size());
        
        for(int i=0;i<queries.size();i++){
		
            if(mp.find(queries[i])!=mp.end()){
                ans[i]=mp[queries[i]];
            }
			
            else{
                   auto it = mp.lower_bound(queries[i]);   // In, it=mp.lower_bound(value), it always points on key which is higher than value
                   if(it!=mp.begin()){
                              it--;
                              ans[i]=(*it).second;
                            }
                   else ans[i]=0;
               }
        }
        return ans;
    }
};