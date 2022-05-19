//  https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode *mergeSortUtil(ListNode *a, ListNode *b){
        ListNode *res=NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->val<b->val){
            res=a;
            res->next=mergeSortUtil(a->next,b);
        }
        else{
            res=b;
            res->next=mergeSortUtil(a,b->next);
        }
        return res;
    }
    void split(ListNode *head, ListNode *&a, ListNode *&b){
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
    ListNode *mergeSort(ListNode *&head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *a=NULL;
        ListNode *b=NULL;
        
        split(head,a,b);
        mergeSort(a);
        mergeSort(b);
        
        head=mergeSortUtil(a,b);
        return head;
    }
    // Main Function
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        return mergeSort(head);
    }
};
