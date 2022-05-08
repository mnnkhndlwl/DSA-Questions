struct Node{
    unordered_map<char, Node *> mp;
    unordered_map<char, int> cnt;
};

class Trie{
  
public:
    Node *root;    
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* temp = root;
        
        for(auto w:word){
            if(!(temp->mp.count(w))){
                temp->mp[w] = new Node();
            }
            temp->cnt[w]++;
            temp=temp->mp[w];
        }
    }
    
    string LCP(int n){
        Node *temp = root;
        string ans="";
        while(1){
            if(temp->mp.size()>1 || temp->mp.size()==0 || temp->cnt.begin()->second!=n) break;
            auto itr = temp->mp.begin();
            ans=ans + itr->first;
            temp=temp->mp[itr->first];
        }
        return ans;
    }
    
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto w:strs) {
            if(w=="") return "";
            t.insert(w);
        }
        return t.LCP(strs.size());
    }
};