class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        
        // q1 -> keep track of the first greater
        deque<int> q1;
		
		// q2 -> keep track of the second greater
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (!q2.empty() && q2.top().first < nums[i]) {
                ans[q2.top().second] = nums[i];
                q2.pop();
            }
    
            while (!q1.empty() && nums[q1.back()] < nums[i]) {
                q2.push({nums[q1.back()], q1.back()});
                q1.pop_back();
            }
            
            q1.push_back(i);
        }
        
        return ans;
    }
};