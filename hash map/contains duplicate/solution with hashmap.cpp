class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> res;          // Create an unordered map
        for(int i = 0; i < nums.size(); ++i){
            if(res[nums[i]])    return true;        // If an element is found in the index already, return true.
            res[nums[i]] = 1;                           // Or insert any value other than 0 to that element.
        }
        return false;
    }
};