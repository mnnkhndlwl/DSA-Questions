class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        int maxi = 0;
        int area = 0;
        while(low<high)
        {
            maxi = min(height[low],height[high])*(high-low);
            area = max(maxi,area);
            if(height[low] > height[high])
            {
                high--;
            }
            else if(height[low] < height[high])
            {
                low++;
            }
            else{
                low++;
                high--;
            }
        }
        return area;
    }
};