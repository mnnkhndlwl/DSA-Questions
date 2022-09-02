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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double> ans;
        
        if(root == NULL)
        {
            return {};
        }
        
        q.push(root);
        
        while(q.empty() == false)
        {
            int levelSize = size(q);long temp=0;
	//	vector<int> currentLevel;
            for(int i = 0; i < levelSize; i++) {
                
            TreeNode* node = q.front();
         //   currentLevel.push_back(node->val);
            q.pop();
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node-> right != NULL)
            {
                q.push(node->right);
            }
                temp+=node->val;
            }
            ans.push_back((double)temp/levelSize);
        }
        return ans;
    }
};