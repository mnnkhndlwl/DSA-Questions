class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> res(n+1);
        res[0] = res[n] = 1;
        long temp = 1;
        int up = n, down = 1;
        for(int i = 1; i < n; i++) {
            temp = temp * up /down;
            res[i] = temp;
            up--;down++;
        }
        return res;
    }
};