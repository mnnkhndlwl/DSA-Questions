 class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
        helper(root,ans,0);
        return ans;
    }
    void helper(TreeNode* root,vector<int> &ans, int level)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == ans.size())
        {
            ans.push_back(root->val);
        }
        
        helper(root->right,ans,level+1);
        helper(root->left,ans,level+1);
    }
};