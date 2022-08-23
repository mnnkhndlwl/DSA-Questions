class Solution {
public:
    int dp[11][1 << 10][2];
    int dfs(string s, int i, int mask, int tight) {
        // if it can reach to the end, check if the value is 0
        if (i == s.size()) return mask == 0 ? 0 : 1;
        // if it is calculated before, return it directly
        if (dp[i][mask][tight] != -1) return dp[i][mask][tight];
        // if `tight` is true, that means the range is only from 0 to s[i]
        // fo example, n = 20 - we cannot put any digit greater than 2 on the first place
        // if `tight` is false, that means we can put 0 - 9 in position i
        int mxDigit = tight ? s[i] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= mxDigit; d++) {
            //if this digit is already included, skip this digit
            if ((1 << d) & mask) continue;
            int newMask = mask;
            // skip leading 0
            // set the new mask
            if (!(d == 0 && mask == 0)) newMask |= (1 << d);
            // find the new tight
            int newTight = tight ? s[i] - '0' == d : 0;
            // try the next position
            ans += dfs(s, i + 1, newMask, newTight);
        }
        // memoize the answer
        return dp[i][mask][tight] = ans;
    }
    
    int countSpecialNumbers(int n) {
        // init dp with value -1
        memset(dp, -1, sizeof(dp));
        // dfs from position 0
        return dfs(to_string(n), 0, 0, 1);
    }
};