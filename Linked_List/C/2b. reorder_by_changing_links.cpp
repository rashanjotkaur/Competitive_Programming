// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// Func 1:
Node* segregate(Node *head) {
        if(head==NULL)
            return NULL;
        Node *zero_dum=newNode(0);
        Node *one_dum=newNode(1);
        Node *two_dum=newNode(2);
        
        Node *zero=zero_dum;
        Node *one=one_dum;
        Node *two=two_dum;
        
        while(head){
            if(head->data==zero->data){
                zero->next=head;
                zero=zero->next;
            }
            else if(head->data==one->data){
                one->next=head;
                one=one->next;
            }
            else if(head->data==two->data){
                two->next=head;
                two=two->next;
            }
            head=head->next;
        }
        if(one_dum->next){
            zero->next=one_dum->next;
            one->next=two_dum->next;
            two->next=NULL;
        }
        else{
            zero->next=two_dum->next;
            two->next=NULL;
        }
        head=zero_dum->next;
        return head;  
}

// Func 2:
Node* newNode(int x){
        Node *temp=new Node(x);
        temp->data=x;
        temp->next=NULL;
        return temp;
}
