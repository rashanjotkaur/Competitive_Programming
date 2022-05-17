// https://leetcode.com/problems/reverse-linked-list/

// Method 1 - No Space Complexity
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
};


// Method 2 - Using Stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        stack <ListNode*> s;
        while(head){
            s.push(head);
            head=head->next;
        }
        
        ListNode *temp=s.top();
        s.pop();
        head=temp;
        while(!s.empty()){
            temp->next=s.top();
            s.pop();
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
