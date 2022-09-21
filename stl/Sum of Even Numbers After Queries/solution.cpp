class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for (int num : nums) if (!(num%2)) sum += num;
        
        for (auto q : queries) {
            int val = q[0], idx = q[1];
            nums[idx] += val;
            
            if(!(nums[idx]%2)) {
                if(!(val%2)) sum += val;
                else sum += nums[idx];
            } 
            else if(val % 2) sum -= (nums[idx] - val);
            ans.push_back(sum);
        }
        return ans;
    }
};