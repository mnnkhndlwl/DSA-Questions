class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<sentence.size();i++) {
            char c = sentence[i];
            mp[c]++;
        }
        if(mp.size() == 26) {
            return true;
        }
        return false;
    }
};