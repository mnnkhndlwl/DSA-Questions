class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size;
        vector<int> dalo;
        for(int i = 0;i<nums1.size();i++)
        {
            dalo.push_back(nums1[i]);
        }
        for(int i = 0;i<nums2.size();i++)
        {
            dalo.push_back(nums2[i]);
        }
        sort(dalo.begin(),dalo.end());
        size = dalo.size();
         if (size % 2 != 0)
      return (double)dalo[size/2];
   return (double)(dalo[(size-1)/2] + dalo[size/2])/2.0;
    }
};