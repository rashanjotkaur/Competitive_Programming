// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

// Func 1
Node* divide(int n, Node *head){
        if(head==NULL || head->next==NULL)
            return head;
  
        Node *tail=head;
        while(tail->next)
            tail=tail->next;
            
        Node *curr=head;
        Node *prev=NULL;
        while(curr && n){
            if(curr->data%2==1){
                Node *temp=newNode(curr->data);
                tail->next=temp;
                tail=tail->next;
                Node *delNode=curr;
                if(prev==NULL)
                    head=curr->next;
                else
                    prev->next=curr->next;
                curr=curr->next;
                delete(delNode);
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            n--;
        }
        return head;
}

// Func 2
Node* newNode(int x){
    Node *temp=new Node(x);
    temp->data=x;
    temp->next=NULL;
    return temp;
}
    
