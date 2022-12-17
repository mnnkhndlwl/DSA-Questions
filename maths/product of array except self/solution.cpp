vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.size()==0||nums.size()==1)
        return nums;
    vector<int> prod(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        prod[i] = prod[i-1]*nums[i-1];
    }
    int p = 1;  
    for(int i=nums.size()-1;i>=0;i--){
        prod[i] *=p;
        p *= nums[i];
    }
    return prod;
    
    
}