class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        count(root);
        return ans;
    }
    
    int count(TreeNode* node){
        if(!node)
            return 0;
        int x = count(node->left), y = count(node->right);
        ans = max(x+y, ans);
        return max(x, y)+1;
    }
};