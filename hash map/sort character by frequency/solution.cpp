class Solution {
public:
    
    static bool compChar(const pair<char,int>& a, const pair<char,int>& b){
       return a.second > b.second; 
    }
    
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp; 
		
		//use a hashmap to count frequency of every distinct character
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
		// copy the hashmap into a vector so that we can sort it based on frequency, descendingly.  
        vector<pair<char,int>> v(mp.begin(), mp.end());
        
		// sort the vector based on the character's frequency, descendingly.  
        sort(v.begin(), v.end(), compChar);
        
		//then iterate over the vector to display the character x times, where x is the number of its frequency. 
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].second; j++){
                ans+=v[i].first;
            }
        }
        
        return ans; 
    }
};