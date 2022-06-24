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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         auto dummy = new ListNode();
        auto node = dummy;
        auto ptr1 = list1;
        auto ptr2 = list2;
        
        while(ptr1 and ptr2)
        {
            if(ptr1->val >= ptr2 -> val)
            {
                node->next=ptr2;
                ptr2 = ptr2->next;
            }
            else
            {
                node->next=ptr1;
                ptr1 = ptr1->next;
            }
            node = node->next;
        }
         node->next = (ptr1) ? ptr1 : ptr2; // last element ko add karrne ke liye
        return dummy->next;
    }
};