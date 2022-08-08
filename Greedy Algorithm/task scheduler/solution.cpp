// Build a hashmap and sort by freq in decreasing order
// Fill the max Freq first at n separation and then fill the remaining in the empty slots
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        for(char c:tasks)hash[c-'A']++;
        sort(hash.begin(),hash.end(),greater<int>());
        int slots=hash[0]-1;
        int idle=slots*n;
        for(int i=1;i<hash.size();i++)
        {
            idle-=min(slots,hash[i]);
        }
        return tasks.size()+max(0,idle);
    }
};

// Example maxFreq is 6 and that of A. and n=3
// A _ _ _ A_ _ _ A_ _ _ A_ _ _ A_ _ _ A
// We have divided it into 5 slots. Now imagine we have to fill 4 Bs. We can use almost 5=slots spaces =min(slots,hash[I]). Had it been 6 Bs still we could use only 5 spaces as
// AB _ _ AB _ _ AB _ _ AB _ _ AB _ _ AB.