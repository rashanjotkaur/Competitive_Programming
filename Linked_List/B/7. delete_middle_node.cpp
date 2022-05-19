// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return NULL;
        ListNode *prev=NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        // Free memory
        delete slow;
        return head;
    }
};
