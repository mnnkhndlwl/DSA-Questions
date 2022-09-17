class Solution {
    bool isPalindrome(string str){
        int n = str.size();
        
        for(int i = 0; i<n/2; i++){
            if(str[i] != str[n-i-1])
                return false;
        }
        
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int sz = words.size();
        
        vector<vector<int>> ans;
        map<string, int> mp;
        set<int> size;
        
        for(int i = 0; i<sz; i++){
            mp[words[i]] = i+1;
            size.insert(words[i].size());
        }
        
        for(int i = 0; i<sz; i++){
            string str = words[i];
            int n = str.size();
            
            string rev = words[i];
            reverse(rev.begin(), rev.end());

            if(mp.count(rev) && mp[rev] != i+1 && mp[rev] != 0)
                ans.push_back({i, mp[rev] - 1});
            
            for(auto k : size){
                if(n <= k)
                    break;
                
                string temp1 = str.substr(0,n-k);
                string temp2 = str.substr(k);
                
                if(isPalindrome(temp1) == true){
                    string rev1 = rev.substr(0, k);
                    
                    if(mp[rev1] != 0 && mp[rev1] != i+1){
                        ans.push_back({mp[rev1] - 1, i});
                }
                    
                if(isPalindrome(temp2) == true){
                    string rev2 = rev.substr(n-k);
                    
                    if(mp[rev2] != 0 && mp[rev2] != i+1)
                        ans.push_back({i, mp[rev2] - 1});
                }
            }
        }
        
        return ans;
    }
};