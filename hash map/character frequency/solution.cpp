vector<int> solve(string str){
//CODE HERE 
  unordered_map<char,int> mp;
    for(char i : str){
        mp[i]++;
    }
    vector<int> ans;
    for(char i : str){
        if(mp[i] != 0){
            ans.push_back(mp[i]);
            mp[i] = 0;
        }
        
    }
    return ans;
}  