class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size()-1, bLen = b.size()-1;
        int carry = 0;
        
        string str;
        while(aLen >= 0 || bLen >= 0 || carry == 1)
        {
            if(aLen >= 0)
                carry += a[aLen--]-'0';
            if(bLen >= 0)
                carry += b[bLen--]-'0';
            
            str = to_string(carry % 2) + str;
            carry /= 2;
        }
        
        return str;
    }
};