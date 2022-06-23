// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) {
	    // code here
	    int i =0;
        int j =0;
	    int k = p.size();
	    int n = s.size();
	    map<char,int> m;
	    for(int i=0;i<k;i++)
	    {
	        m[p[i]]++;
	    }
	    int ans = 0;
	    int count = m.size();
	    while(j<n)
	    {
	        if(j-i+1<k)
	        {
	            m[s[j]]--;
	        if(m[s[j]] == 0)
	            {
	            count--;
	            }
	            j++;
	        }
	        else if((j-i+1) == k)
	        {
	             m[s[j]]--;
	        if(m[s[j]] == 0)
	            {
	            count--;
	            }
	            if(count == 0)
	            {
	                ans++;
	            }
	            m[s[i]]++;
       if(m[s[i]]==1){
         count++;
       }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends