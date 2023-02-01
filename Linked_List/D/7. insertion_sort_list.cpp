// Insertion Sort List
// Problem Link: https://leetcode.com/problems/insertion-sort-list/

// Method 2: Using for loop 
ListNode* insertionSortList(ListNode* head) {
        for(ListNode *curr=head;curr!=NULL;curr=curr->next){
            for(ListNode *prev=head;prev!=curr;prev=prev->next){
                if(prev->val>curr->val){
                    int temp=prev->val;
                    prev->val=curr->val;
                    curr->val=temp;
                }
            }
        }
        return head;
}


// Method 1: Using while loop
ListNode* insertionSortList(ListNode* head) {
        ListNode *curr=head;
        while(curr){
            ListNode *prev=head;
            while(prev!=curr){
                if(prev->val>curr->val){
                    int temp=curr->val;
                    curr->val=prev->val;
                    prev->val=temp;
                }
                prev=prev->next;
            }
            curr=curr->next;
        }
        return head;
}
