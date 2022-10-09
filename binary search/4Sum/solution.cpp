vector<vector> fourSum(vector& nums, int target) {

    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    
    vector<vector<int>>ans;
    
    if(nums.empty())
        return ans;

    for(int i=0;i<n;i++)
    {
        
        for(int j=i+1;j<n;j++)
        {
            int start = j+1;
            int end = n-1;
        
            long long sum = (long long)target- (long long)nums[i]-(long long)nums[j];
            
            while(start<end)
            {
                int two_sum = nums[start]+nums[end];   
            
                if(two_sum<sum)
                    start++;
                
                else if(two_sum>sum)
                    end--;
                        
                else
                {
                    vector<int>temp(4,0);
                    
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[start];
                    temp[3] = nums[end];
                    
                    ans.push_back(temp);
                    
                  while(start<end && nums[start]==temp[2])  //This is for avoid duplicate
                    start++;
                
                  while(start<end && nums[end]==temp[3])  // This is for avoid duplicate
                    end--;
                }
                
             }
         
            while(j+1<n && nums[j]==nums[j+1])  //This is for avoid duplicate
                j++;
          }
        
        while(i+1<n && nums[i]==nums[i+1])   // This is for the avoid duplicate.
            i++;
    }
    
    return ans;
}