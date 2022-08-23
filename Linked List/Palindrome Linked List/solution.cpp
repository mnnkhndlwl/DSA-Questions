class Solution {   
private:
    bool isPalin(vector<int>&arr){
        int n=arr.size();
        int start=0, end=n-1;
        while(start<=end){
            if(arr[start] != arr[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }   
        return isPalin(arr);
    }
};