class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].length();
        unordered_map<string, int> available;
        for(string w : words){
            available[w]++;
        }
        
        unordered_map<string, int> used;
        vector<int> matches;
        for(int offset = 0; offset < n; ++offset){
            used.clear();
            int start = offset;
            int end = start + n; // first disincluded
            while(start + n * words.size() <= s.length() && end <= s.length()){
                string k = s.substr(end - n, n);
                // invalid - jump start forward to avoid it
                if(available.find(k) == available.end()){
                    used.clear();
                    start = end;
                    end = start + n;
                }
                else{
                    used[k]++; // use k
                    // while there's overuse - move start forward
                    while(used[k] > available[k]){
                        used[s.substr(start, n)]--;
                        start += n;
                    }
                    
                    // check for match, move end forward
                    if(end - start == words.size() * n){
                        matches.push_back(start);
                    }
                    end += n;
                } 
            }
        }
        
        return matches;
    }
};