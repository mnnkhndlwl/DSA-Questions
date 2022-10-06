void solve(TreeNode * root, string s , vector<string>&ans){
        if(!root) return;
        if(!root->left && !root->right){
            s+= to_string(root->val);
            ans.push_back(s);
        }
        s+=to_string(root->val)+"->";
        
        solve(root->left , s, ans);
        solve(root->right , s, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string str = "";
        solve(root,str,s);
        
        return s;
    }
};