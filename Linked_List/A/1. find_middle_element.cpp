// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
