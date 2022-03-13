class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> h_map;
        for(int i=0;i<nums.size();++i)
        {
            int num=nums[i];
            int complement = target-num;
            auto it = h_map.find(complement);
            if(it!=h_map.end())
            {
                return {it->second,i};
            }
            h_map[num]=i;
        }
        return{};
    }
};