class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        map<int,int> mp;                  // create a map for store value and their corresponding weight
        
        // store items1 value and their added weight
        for(auto it:items1)
        {
            mp[it[0]] += it[1];
        }
        
        // store items1 value and their added weight
        for(auto it:items2)
        {
            mp[it[0]] += it[1];
        }
        
        // store the answer
        vector<vector<int>> ans;
        for(auto it:mp)
        {
            ans.push_back({it.first,it.second});
        }
        
        return ans;
    }
};