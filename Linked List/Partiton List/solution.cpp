/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* large_head = large;
        
        while(head)
        {
            if(head->val<x)
            {
                small->next = head;
                head = head->next;
                small = small->next;
                small -> next = NULL;
            }
            else{
                large->next = head;
                head = head->next;
                large = large->next;
                large -> next = NULL;
            }
        }
        
        small -> next = large_head -> next;

        return small_head -> next;
        
    }
};