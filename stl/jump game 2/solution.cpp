int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int jump=1, maxi=nums[0], curr=nums[0];
        for(int i=0;i<n-1;i++)
        {
            maxi=max(maxi, nums[i]+i);
            if(curr==i)
            {
                jump++;
                curr=maxi;
            }
        }
        return jump;
    }