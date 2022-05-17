// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode *temp1=head;
        ListNode *temp2=temp1->next;
        
        while(temp2){
            swap(temp1->val,temp2->val);
            if(temp2->next==NULL)
                break;
            temp1=temp2->next;
            temp2=temp1->next; 
        }
        return head;
    }
};
