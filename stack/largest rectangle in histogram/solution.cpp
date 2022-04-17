class Solution {
    private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        //next smaller element logic
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1; i>=0; i--){
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans will be top of stack
            ans[i] = s.top();
            s.push(i);  //we need to push index over here
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n){
        //next smaller element logic
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0; i<n; i++){   //loop change for prev smaller
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans will be top of stack
            ans[i] = s.top();
            s.push(i);  //we need to push index over here
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);    //for next smaller element 
        next = nextSmallerElement(heights, n);
        
        vector<int> prev(n);    //for prev smaller element
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i = 0; i<n; i++){
            int length = heights[i];    //const already given
            
            //now corner case if all histograms equal then next = -1, everything -1, our width -ve so does area
            if(next[i]==-1){
                next[i] = n;    //put in last
            }
            int breadth = next[i] - prev[i] - 1;  //n-p-1 => max width
    //find breadth after updating all values of next        
    
            //we need to find area
            int newArea = length*breadth;
            
            area = max(area, newArea);
        }
        return area;    //return ans
    }
};