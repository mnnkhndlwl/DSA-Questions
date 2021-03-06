class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
         if(find(nums.begin(),nums.end(),target)==nums.end()) return {-1,-1};
         ans.push_back(search(nums, target, true));
        if (ans[0] != -1) {
            ans.push_back(search(nums, target, false));
        }
        return ans;
    }
    int search(vector<int>& nums, int target, bool findStartIndex) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                // potential ans found
                ans = mid;
                //when our ans will be found binary search loop will break
                if (findStartIndex) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
    
};
