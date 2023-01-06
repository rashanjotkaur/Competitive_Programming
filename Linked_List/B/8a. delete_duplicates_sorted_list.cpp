// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode *curr=head;
        ListNode *forw=head->next;
        while(curr && forw){
            if(curr->val==forw->val){
                ListNode *temp=forw;
                curr->next=forw->next;
                delete(temp);
                forw=curr->next;
            }
            else{
                curr=forw;
                forw=curr->next;
            }
        }
        return head;
    }
};
