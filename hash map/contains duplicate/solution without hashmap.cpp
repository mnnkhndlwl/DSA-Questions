class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int prev = nums[0];
        for(size_t i = 1; i < nums.size(); i++){
            if(prev == nums[i]) return true;
            prev = nums[i];
        }
        return false;
    }
};