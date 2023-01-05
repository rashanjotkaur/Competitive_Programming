//  https://leetcode.com/problems/reorder-list/description/

// Func 1 - reorderList
void reorderList(ListNode* &head) {
        if(head==NULL)
            return ;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head1=head;
        ListNode *head2=slow->next;
        slow->next=NULL;

        reverseList(head2);
        
        head=newNode(0);
        ListNode* curr=head;
        while(head1 || head2){
            if(head1){
                curr->next=head1;
                curr=curr->next;
                head1=head1->next;
            }
            if(head2){
                curr->next=head2;
                curr=curr->next;
                head2=head2->next;
            }
        }
        head=head->next;
}

// Func 2 - reverseList
void reverseList(ListNode* &head){
        if(head==NULL)
            return ;
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forw=NULL;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        head=prev;
}

// Func 3 - newNode
ListNode* newNode(int x){
        ListNode* temp=new ListNode;
        temp->val=x;
        temp->next=NULL;
        return temp;
}

// Func 4 - printList
void printList(ListNode* head){
        if(head==NULL)
            return ;
        cout<<"List"<<endl;
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
}
