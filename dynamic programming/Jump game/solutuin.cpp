class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return create(nums, 0, dp);
    }
private:
    bool create(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx == nums.size() -1) return true;
        if(nums[idx] == 0) return false;
        
        if(dp[idx] != -1) return dp[idx]; //overlapping subproblems
        int reach = idx + nums[idx];
        for(int jump=idx + 1; jump <= reach; jump++) {
            if(jump < nums.size() && create(nums, jump, dp)) 
                return dp[idx] = true; //memoizing for particular index.
        }
        
        return dp[idx] = false; //memoizing for particular index.
    }
};

// another  solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
        
    }
};
