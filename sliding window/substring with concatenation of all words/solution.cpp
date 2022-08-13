class Solution {
public:

unordered_map<string,int>m;// map to take the count of the current substrings 
bool isfound(string &s,int i, int k,int n,unordered_map<string,int>mp){
    
  for(int j= i ;j<=(i+k-1);j+=n){
     m[s.substr(j,n)]++; // pushing all the substrings in the window k of size same as word size
  } 
    for(auto ele:m){
        
        if(mp[ele.first]!=ele.second){// if the count of the string matches then true else false
            
            m.clear();
            return false;
        };
    }
     m.clear();
    return true;
    
}

vector<int> findSubstring(string s, vector<string>& words) {
    
    unordered_map<string ,int>mp;
    vector<int>ans;
    int count=0;
    for(auto ele:words)mp[ele]++,count++;// take all the word and push it in to the map
    
    int n=words[0].size();
    int k = count*n; // size of the window 
    
    for(int i=0 ;i <s.size();i++){
        if((i+k-1)>s.size())break; // no need to go if the window reach at the end
        if(isfound(s,i,k,n,mp))ans.push_back(i);// pushgin the index 
    }

    return ans;// retuning the ans 
    
}
};