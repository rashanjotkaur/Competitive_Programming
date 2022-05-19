// https://leetcode.com/problems/merge-two-sorted-lists/

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
        ListNode *temp=NULL;
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
