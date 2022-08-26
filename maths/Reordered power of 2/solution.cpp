public:
    bool reorderedPowerOf2(int n) {
        string number = sortedDigits(n);

        for (int i = 0; i < 30; ++i) {
            string powerOfTwo = sortedDigits(1 << i);
            if (number == powerOfTwo)
                return true;
        }

        return false;
    }

private:
    string sortedDigits(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        return digits;
    }


//     The " << " is a bitwise left-shift operator.
// So ,

// 1      = 00000000 00000000 00000000 00000001 = 1
// 1 << 1 = 00000000 00000000 00000000 00000010 = 2
// 1 << 8 = 00000000 00000000 00000001 00000000 = 256
// for e.g., 1<<6 will be 1(2^6)= 64

// So here we are just trying to store, 2 to the power i