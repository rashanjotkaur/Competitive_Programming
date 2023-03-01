// https://leetcode.com/problems/merge-two-sorted-lists/
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1#

// Method - By comparing two lists - Easy to Understand
// Func 1:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list=NULL;
        list=newNode(-101);
        ListNode *temp=list;
        while(list1 && list2){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        while(list1){
            temp->next=list1;
            temp=temp->next;
            list1=list1->next;
        }
        while(list2){
            temp->next=list2;
            temp=temp->next;
            list2=list2->next;
        }
        return list->next;
}
// Func 2:
ListNode* newNode(int x){
        ListNode *temp=new ListNode();
        temp->val=x;
        temp->next=NULL;
        return temp;
}


// Recursive Function
Node* sortedMerge(Node* a, Node* b){  
    Node *res=NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<b->data){
        res=a;
        res->next=sortedMerge(a->next,b);
    }
    else{
        res=b;
        res->next=sortedMerge(a,b->next);
    }
    return res;
} 


// Iterative Method - Preferred
// Func 1 - mergeTwoLists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=newNode(0);
        ListNode* curr=head;
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next=list1;
                curr=curr->next;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                curr=curr->next;
                list2=list2->next;
            }
        }
        while(list1){
            curr->next=list1;
            curr=curr->next;
            list1=list1->next;
        }
        while(list2){
            curr->next=list2;
            curr=curr->next;
            list2=list2->next;
        }
        head=head->next;
        return head;
}
// Func 2 - newNode
ListNode* newNode(int x){
        ListNode* temp=new ListNode;
        temp->val=x;
        temp->next=NULL;
        return temp;
}


// Iterative Method 
class Solution {
public:
    ListNode* newNode(int data){
        ListNode *temp=new ListNode();
        temp->val=data;
        temp->next=NULL;
        return temp;
    }
    void insert(ListNode *&head, int x){
        if(head==NULL){
            head=newNode(x);
            return ;
        }
        ListNode *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=newNode(x);
    }
    ListNode* merge(ListNode *a, ListNode *b){
        ListNode *res=NULL;
        while(a && b){
            if(a->val<b->val){
                insert(res,a->val);
                a=a->next;
            }
            else{
                insert(res,b->val);
                b=b->next;
            }
        }
        while(a){
            insert(res,a->val);
            a=a->next;
        }
        while(b){
            insert(res,b->val);
            b=b->next;
        }
        return res;
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a==NULL && b==NULL)
            return NULL;
        return merge(a,b);
    }
};
