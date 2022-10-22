class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int,int> mp;
        
        for(int i =0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        
        int max = INT_MIN;
        int ans;
        for (auto i : mp)
        {
            if(i.second > nums.size()/2 and i.second > max){
                max = i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};