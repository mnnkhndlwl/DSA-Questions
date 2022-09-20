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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> res;
        for(int i = 0;i<lists.size();i++) {
            ListNode* ptr = lists[i];
            while(ptr != nullptr) {
                res.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        sort(res.begin(),res.end());
        ListNode* root = arrayToList(res, res.size());
        return root;
    }
    ListNode *arrayToList(vector<int> arr, int n)
{
    ListNode *root = NULL;
    for (int i = n-1; i >= 0 ; i--)
        insert(&root, arr[i]);
    return root;
}
    void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode;
    temp->val = item;
    temp->next = *root;
    *root = temp;
}
};