


// } Driver Code Ends
//User function Template for C++

struct node{
        int start,end,ind;
    };
    bool cmp(node a,node b)
    {
        if(a.end == b.end)
        {
            return a.ind<b.ind;
        }
        return a.end<b.end;
    }
    
class Solution{
public:
    
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &e){
        vector<node> v;
        vector<int> ans;
        node t;
        
        for(int i=0;i<s.size();i++)
        {
            t.start = s[i];
            t.end = e[i];
            t.ind = i+1;
            v.push_back(t);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        ans.push_back(v[0].ind);
        
        t=v[0];
        
        for(int i=1;i<s.size();i++)
        {
            if(v[i].start>t.end)
            {
                t=v[i];
                ans.push_back(v[i].ind);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

