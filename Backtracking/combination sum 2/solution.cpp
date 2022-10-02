class Solution {
public:
     void solve(vector<vector<int>>& ans,vector<int>& nums,vector<int> &v,int target,int index) {
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index;i<v.size();i++){
              if(v[i] > target)  //no point to check if the target element is smaller than ith element
                break;
           // if(v[i] <= target) {
                //target-=v[i];
               
                if(i>index && v[i] == v[i-1]) //to avoid picking same elements and thus avoid duplicates
                continue;
             nums.push_back(v[i]);
                solve(ans,nums,v,target-v[i],i+1);
               // target+=v[i];
                nums.pop_back();
            //}
        }
       // return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int> nums;
        sort(candidates.begin(),candidates.end());
        solve(ans,nums,candidates,target,0);
        return ans;
    }
};