

class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1;
        int sum = (n*n + n)/2;
        for(int i = 1;i<=n;i++) {
           int sum1 = (i*i + i)/2;
           int sum2 = sum-sum1+i;
            if(sum1 == sum2){
                ans = i;
                break;
            }
        }
        return ans;
    }
};