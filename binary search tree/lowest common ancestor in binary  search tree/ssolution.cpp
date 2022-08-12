class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int current = root->val;
        if(current > p->val and current > q->val)
        {
           return lowestCommonAncestor(root->left,p,q);
        }
        else if(current < p->val and current < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};