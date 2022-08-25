class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     map<char,int>m;
    for(auto it : magazine){
        m[it]++;
    }
    for(auto i : ransomNote){
      if(m[i]==0) return false;
        m[i]--;
    }
  return true;  
    }
};