class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // we need to sort the given vector
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>res; // vector to store our ans
        
        if(nums.size()<3)
        {
            return res;
        }
        
        for(int i=0;i<nums.size();i++) // move for a
        {
            
            if(i == 0 || ( i > 0 && nums[i] != nums[i-1])) // we need to change 'a' until it 
                //is not equivalent to it's previous value
            {
                int low = i+1;
                int high = nums.size() - 1;
                int sum = 0 - nums[i]; // sum (of low and high should be equal to '-a'
                while(low<high) // if low crosses high we need to stop
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                   
                    while(low<high and nums[low] == nums[low+1]) low++;//we need to change low and                  // high until they are not equal to their previous value
                    while(low<high and nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                  }
                    else if(nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return res;
    }
};