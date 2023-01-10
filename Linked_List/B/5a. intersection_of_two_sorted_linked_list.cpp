// https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/

// Func 1
Node* findIntersection(Node* head1, Node* head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node *head=NULL;
    while(head1 && head2){
        if(head1->data==head2->data){
            insert(head,head1->data);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data<head2->data)
            head1=head1->next;
        else
            head2=head2->next;
    }
    return head;
}

// Func 2
void insert(Node* &head,int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
}

// Func 3
Node* newNode(int x){
    Node *temp=new Node(x);
    temp->data=x;
    temp->next=NULL;
    return temp;
}

