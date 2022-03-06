class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        
        int start=0,end = n*m-1;
        int r,c;
        while(start<=end){
            int mid = start+ (end-start)/2;
            r = mid/m;
            c = mid%m;
            
            if(matrix[r][c]==target)
                return 1;
            else if(matrix[r][c]< target)
                start = mid+1;
            else 
                end = mid-1;
        }
        return 0;
    }
};