/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
      
        int start = 0;
        int end = arr.length()-1;
        
        if(end < 2) return -1; 
        
        int peak = findPeak(arr,0,end);
        int leftPos = binarySearch(arr,target,0,peak);
        int rightPos = binarySearch(arr,target,peak+1,end);
        
        if(leftPos == -1)
            return rightPos;
        else return leftPos;
    }
    
   int binarySearch(MountainArray &arr, int target,int start,int end){

       bool isAsc = arr.get(start) < arr.get(end);

         while(start <= end ){
            int mid = start +(end - start) /2 ;
        
        if(arr.get(mid) == target )
            return mid;
             
        if(isAsc){             
            if(target > arr.get(mid))
                 start = mid + 1;
           else if(target < arr.get(mid))
                end = mid -1 ;
             }else{
              
            if(target > arr.get(mid))
                 end = mid - 1;
           else if(target < arr.get(mid))
                start = mid + 1 ;
           }
         }
         return -1;
     }
    int findPeak(MountainArray &arr,int start,int end){
        while(start != end){
            int mid = start + (end-start)/2;
            if(arr.get(mid) > arr.get(mid+1))
                end = mid;
            else if( arr.get(mid) < arr.get(mid+1))
                start = mid+1;       
        }
        return start;
    }
    
};