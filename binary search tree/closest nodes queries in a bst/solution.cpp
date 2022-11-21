/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL)
            return;
        else
        {
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> arr;
        inorder(root,arr);
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i =0;i<q.size();i++)
        {
           
            int l = lower_bound(arr.begin(),arr.end(),q[i])-arr.begin();
            if(l>=0 && l<n)
            {
                if(arr[l]!=q[i])
                   l-=1;
                if(l<0)
                    l=-1;
                else
                   l=arr[l];
            }
            else
            {
                l=arr.back();
            }
            
                
            int h = upper_bound(arr.begin(),arr.end(),q[i])-arr.begin();
            if(l!=-1 && q[i]==l)
                h=q[i];
            else if(h>=0 && h<n)
            {
                h=arr[h];
            }
            else
            {
                h=-1;
            }
            ans.push_back({l,h});
        }
        return ans;
    }
};