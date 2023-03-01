// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// Method 1 - Easy to Understand
ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        while(head && head->next && head->val==head->next->val)
            head=head->next;
        ListNode *temp=head;
        while(temp && temp->next){
            if(temp->val==temp->next->val)
                temp->next=temp->next->next;
            else    
                temp=temp->next;
        }
        return head;
}

// Method 2-Using Pointers
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


// Method 3 - Using Merge Sort
// Func 1 - deleteDuplicates
ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        mergeSort(head);
        return head;
}

// Func 2 - mergeSort
ListNode* mergeSort(ListNode* &head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *a=NULL;
        ListNode *b=NULL;
        split(head,a,b);
        
        mergeSort(a);
        mergeSort(b);
        head=merge(a,b);
        return head;
}

// Func 3 - split
void split(ListNode *head, ListNode* &a, ListNode* &b){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        a=head;
        b=slow->next;
        slow->next=NULL;
}

// Func 4 - merge
ListNode* merge(ListNode *a, ListNode *b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode *res=NULL;
        if(a->val<b->val){
            res=a;
            res->next=merge(a->next,b);
        }
        else if(b->val<a->val){
            res=b;
            res->next=merge(a,b->next);
        }
        else if(a->val==b->val){
            res=a; // here we will add node for the one time only.
            res->next=merge(a->next,b->next);
        }
        return res;
}
    
    
    
