class Solution {
public:
    
    void f(long long num,int n,int k,vector<int> &ans){
        if(n==0) {ans.push_back(num);return;}
        int lower=((num==0)?1:0);
        for(int i=lower;i<10;i++){
            if(num and abs(i-num%10)!=k) continue;
            num*=10;num+=i;
            f(num,n-1,k,ans);
            num/=10;
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        long long num=0;
        f(num,n,k,ans);
        return ans;
    }
};
Explanation :

significance of parameters :

num --> the number that is generated recursively and the constraints of adjacent digits are checked on this number
n --> length of the number
ans --> for storing the final answer.

int lower=((num==0)?1:0); --> this line basically checks if the number is 0 , if the number is 0 then we should set the first digit in the number to 1-9 according to the constraint . So every time we start we can append any digit in range 1-9 and in all other cases 0-9 any digit can be appended .

if(num and abs(i-num%10)!=k) continue; --> this line checks if the difference between current digit to be inserted and the previous digit is k , if it is not then simply try adding any other digit .

f(num,n-1,k,ans); --> Here we recursively search for all valid combinations of length n-1 that can be formed by appending digits to num.

Hope this helps :)