Here we calculate gcd of P and q for reducing count of p and q(no need to repeat way of ray more than 1 time.)

if p (length of room) = q (distance from bottom where ray meet) then it is only catch by 1.
if p%2 = 0 then no matter what is q ray will only catch by 2 after n reflection (where n is even number).
if p is not even and q is odd then ray will catch by 1.
any of these condition will not match then ray will caught by 0.

class Solution {
public:
    int mirrorReflection(int p, int q) {
	
        // __gcd( _ , _ ) is inbuilt function	
        int g = __gcd(p,q);
        p/=g;
        q/=g;
        ****
        if(p==q) return 1;
        if(p%2==0) return 2;
        if(q%2==1) return 1;
        return 0;
    }
};