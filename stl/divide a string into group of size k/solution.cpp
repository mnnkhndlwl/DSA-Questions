class Solution {
public:
    vector<string> divideString(string str, int K, char ch) {
        int N = str.size();
    int j = 0, i = 0;
    vector<string> result;
    string res = "";
    while (j < N) {
        res += str[j];
        if (res.size() == K) {
            result.push_back(res);
            res = "";
        }
        j++;
    }
 
    if (res != "") {
        while (res.size() < K) {
            res += ch;
        }
        result.push_back(res);
    }
    return result;
    }
};