
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        size_t n = letters.size();
    int low = 0;
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (letters.at(mid) <= target)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans == 0 ? letters.at(0) : letters.at(ans);
    }
};