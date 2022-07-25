 class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool> &m)
    {
        if(s1 == s2) return true;
        
        string code = s1 + '$' + s2;
        
        if(m.find(code) != m.end())
        {
            return m[code];
        }
        
        for(int k=1;k<s1.size();k++)
        {
            //if not swapped
		if((solve(s1.substr(0, k), s2.substr(0, k), m) &&
		solve(s1.substr(k), s2.substr(k), m)) ||

		//if swapped
		(solve(s1.substr(0, k), s2.substr(s1.size() - k), m) &&
		solve(s1.substr(k), s2.substr(0, s1.size() - k), m)))
			return m[code] = true;
        }
        return m[code] = false;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>m;
        return solve(s1,s2,m);
    }
};