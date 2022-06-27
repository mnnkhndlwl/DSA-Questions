int knapSack(int W, int wt[], int val[], int n) 
    { 
       //dp solution
       int k[n+1][W+1];
       for(int i=0;i<=n;i++){
           for(int w=0;w<=W;w++){
               if(W==0 || i==0)
                    k[i][w]=0;
               else if(wt[i-1] <= w){  
                    k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
               }else{
                  k[i][w]= k[i-1][w];
               }
           }
        }
        return k[n][W];
    }