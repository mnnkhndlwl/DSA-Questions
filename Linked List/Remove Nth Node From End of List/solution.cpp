class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(len==1 && n==1)
            return NULL;
        if(len==n){
            head = head->next;
            return head;
        }
        int p = len-n+1;
        ListNode* temp = head;
        for(int i=0; i<p-2; ++i){
            temp=temp->next;
        }
        if(temp->next->next == NULL){
            temp->next = NULL;
        }
        else{
            temp->next = temp->next->next;
        }
        return head; 
    }
};