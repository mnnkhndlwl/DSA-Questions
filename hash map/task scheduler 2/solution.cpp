// **This question is similar to that of task scheduler bas ismain humain task jis order main diye hain usmain krna h **

// Toh hum kya karenge ek map banayenge[ task no->NEXT TIME wo kab chal sakta h ]
// sabse phle ek ek krke task pe Iterate karenge or ek variable lenge currenttime ke liye jo ki zero se start hoga
// phir apan dekhenge kya yeh task mere map main present h ki nai agar nai h toh wo task mtlb usko hum abhi execute kr sakte hain toh uss case main usse map main dalke uska next time update krdenge currenttime +space+1 or agar h toh 2 possibility h ki uski value jo h current time se yaa toh choti yaa barabar hogi yaa badi hogi
// agar choti h toh usko execute krke uska next time update krdenge currenttime +space+1 se
// agar badi h toh humain break lena padega toh hum currenttime ko uski value+1 se update krke task ki value ko next time se update krdenge
// bas end main jo currenttime hoga wo humara ans h

long long taskSchedulerII(vector<int>& tasks, int space) 
    {
        unordered_map<long long ,long long> m;
        int ans=0;
        long long int  curr=0;
        for(int i=0;i<tasks.size();i++)
        {
            
            if(m.find(tasks[i])==m.end())
            {
                m[tasks[i]]=1+space+curr;
                curr++;
            }
            else
            {
                if(m[tasks[i]]>curr)
                {
                    curr=m[tasks[i]];
                }
                m[tasks[i]]=space+curr+1;  
                curr++;
            }     
        }
        return curr;
        
        
    }