class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       //same as add 1
        int carry = 1;
        
        // propagate carry
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        
        // handle the last carry if any
        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
     }
};