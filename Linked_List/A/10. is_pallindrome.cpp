// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* reverse(ListNode *head){
        if(head==NULL)
            return NULL;
        
        ListNode *curr=head;
        ListNode *next=NULL;
        ListNode *prev=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;       
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return false;
        
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *rev=reverse(slow);
        ListNode* forw=head;
        while(rev){
            if(rev->val!=forw->val)
                return false;
            
            rev=rev->next;
            forw=forw->next;
        }
        return true;
    }
};
