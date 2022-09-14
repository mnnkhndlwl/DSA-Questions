class Solution {
public:
    void preorderTraversal(TreeNode* root,vector<int> &path,int &cnt)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            path[root->val]++;
            int countOdd=0;
            for(int i=0;i<10;i++)
            {
                if(path[i]%2==1)
                    countOdd++;
            }
            if(countOdd<=1)
                cnt++;
            path[root->val]--;
            return;
        }
        path[root->val]++;
        if(root->left)
        {
        preorderTraversal(root->left,path,cnt);
        }
        if(root->right)
        {
        preorderTraversal(root->right,path,cnt);  
        }
        path[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10,0);
        int cnt=0;
        preorderTraversal(root,path,cnt);
        return cnt;
    }
};