 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int i=0;
        int j=arr.size()-1;
        vector<int> ans;
        while(j-i>=k)
        {
            if(abs(arr[i]-x)>abs(arr[j]-x))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        for(int p=i;p<=j;p++)
            ans.push_back(arr[p]);
        return ans;
    }