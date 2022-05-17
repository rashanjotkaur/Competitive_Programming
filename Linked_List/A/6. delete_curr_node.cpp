// https://leetcode.com/problems/delete-node-in-a-linked-list/

class Solution {
public:
    void deleteNode(ListNode* head) {
        ListNode *next=head->next;
        head->val=next->val;
        head->next=next->next;
    }
};
