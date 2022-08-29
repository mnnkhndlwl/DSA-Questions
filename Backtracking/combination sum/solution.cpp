class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        
        Backtrack(ans, candidates, nums, target, 0);
        
        return ans;
    }
    
private:
    void Backtrack(vector<vector<int>>& ans, const vector<int>& v, vector<int>& nums, int& target, int index)
    {
        if (target == 0)
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = index; i < v.size(); i++)
        {
            if (v[i] <= target)
            {
                target -= v[i];
                nums.push_back(v[i]);
                
                Backtrack(ans, v, nums, target, i);
                
                target += v[i];
                nums.pop_back();
            }
        }
    }
};