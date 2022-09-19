class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};
        map<int,vector<char>> m;
        m[1] = {};
        m[2] = {'a','b','c'};
        m[3] = {'d','e','f'};
        m[4] = {'g','h','i'};
        m[5] = {'j','k','l'};
        m[6] = {'m','n','o'};
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};

        string tmp="";
        vector<string> ans;
        int start = 0;
        func(start,tmp,ans,digits,m);
        return ans;
    }
private:
    void func(int start,string& tmp,vector<string>& ans,string& digits,map<int,vector<char>>& m){
        if(start == digits.size()){
            ans.push_back(tmp);
            return;
        }
        int t = digits[start]-'0';
        for(auto it:m[t]){
            tmp+=it;
            func(start+1,tmp,ans,digits,m);
            tmp.pop_back();
        }
    }
};