// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public int trap(int[] height) {
        int i = 0, j = height.length - 1, ans = 0, mx = 0, mi = 0;
        // two pointers 
        // pointer i from the left
        // pointer j from the right
        while (i <= j) {
            // take the min height 
            mi = Math.min(height[i], height[j]);
            // find the max min height
            mx = Math.max(mx, mi);
            // the units of water being tapped is the diffence between max height and min height
            ans += mx - mi;
            // move the pointer i if height[i] is smaller
            if (height[i] < height[j]) i++;
            // else move pointer j
            else j--;
        }
        return ans;
    }
}