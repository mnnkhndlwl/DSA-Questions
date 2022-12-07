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
    int rangeSumBST(TreeNode* root, int L, int R) {
      int ans = 0;
        if(root->val >=L && root->val<=R) {
            ans += root->val;
        }
        if(root -> left != NULL){
            
            ans += rangeSumBST(root->left, L, R);
        }
        if(root -> right != NULL){
            
            ans += rangeSumBST(root->right, L, R);
        }
        return ans;  
    }
};