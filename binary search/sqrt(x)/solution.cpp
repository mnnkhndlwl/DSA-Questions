class Solution {
public:
    int mySqrt(int x) {
         int high = x;
        int low = 0;
        int ans = 0;
        
        while(low<=high){
            
            long long int mid = low + (high-low)/2;
            
            if(mid*mid == x){
                return mid;
            }else if(mid*mid>x){
                high = mid-1;
            }else{
                 low = mid+1;
            }
        }
      return low-1;
    }
};