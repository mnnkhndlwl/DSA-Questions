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
    void buildMap(TreeNode* root, unordered_map<int, vector<int>>& m) {
        if (root->left) {
            buildMap(root->left, m);
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
        }
        
        if (root->right) {
            buildMap(root->right, m);
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        // Use map to hold the graph
        unordered_map<int, vector<int>> m;
        
        int ans = 0;
        
        // Build the map by passing root node and the map
        buildMap(root, m);
        
        // Run bfs to find longest path
        queue<int> q;
        unordered_map<int,bool> seen;
        q.push(start);
        seen[start]=true;
        
        for(; q.size() ; ans++){
            int n= q.size();
            while(n--){
                auto node= q.front();  q.pop();
                for(auto x:m[node]){
                    if(!seen[x]){
                        q.push(x);
                        seen[x]=true;
                    }
                }
            }
        }
        return ans-1;
    }
};