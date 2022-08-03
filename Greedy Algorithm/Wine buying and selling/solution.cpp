class Solution{
  public:
  int wineSelling(vector<int>& a){
      int ans=0,i, b=0,s=0, n=a.size();
      while(b<n && s<n){
          while(a[b]<=0){
              b++;
              if(b==n)   return ans;
          }
          while(a[s]>=0){
              s++;
              if(s==n)   return ans;
          }
          if(abs(a[s])>=abs(a[b])){
              ans+= abs(s-b) * a[b];
              a[s] = a[s] + a[b];
              a[b] = 0;
          }else{
              ans+= abs(s-b) * abs(a[s]);
              a[b] = a[b] + a[s]; 
              a[s] = 0;
          }
      }
      return ans;
  }
};