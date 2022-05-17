// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Hard

// Method 1
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return head;
        
        ListNode* temp=head;
        int rem=0;
        while(temp){
            rem++;
            temp=temp->next;
            if(rem>=k)
                break;
        }
        if(rem<k)
            return head;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        int i=0;
        while(curr && i<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        
        if(next)
            head->next=reverseKGroup(next,k);
        return prev;
    }
};
