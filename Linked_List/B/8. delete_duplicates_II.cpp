// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *comp=head->next;
        if(head->val==comp->val){
            while(comp && head->val==comp->val)
                comp=comp->next;
            head=comp;
            head=deleteDuplicates(head);
            return head;
        }
        else{
            head->next=deleteDuplicates(comp);
            return head;
        }
    }
};
