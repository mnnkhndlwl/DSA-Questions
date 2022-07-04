int dp[22][1002];

int find_total_subset(vector<int>& nums, int sum, int n)
{

int i, j;
dp[0][0]=1;
// we are having whole numbers so first column of matrix is not initialised.
for(j=1;j<sum+1;j++)
{
    dp[0][j]=0;
}

for(i=1;i<n+1;i++)
{
    for(j=0;j<sum+1;j++)
    {
        if(nums[i-1]<=j)
        {
            dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
        }
        else if(nums[i-1]>j)
        {
            dp[i][j]=dp[i-1][j];
        }
    }
}
return dp[n][sum];
}

class Solution {
public:
int findTargetSumWays(vector<int>& nums, int target) {

    int total_sum=0, i;
    for(i=0;i<nums.size();i++)
    {
        total_sum=total_sum + nums[i];
    }
	
	// in these three corner cases no combination is possible.
    if(total_sum<target || total_sum+target<0 || ((target+total_sum)&1==1))
    {
        return 0;
    }
    int subset_1=(total_sum+target)/2;
    return find_total_subset(nums, subset_1, nums.size());
}
};