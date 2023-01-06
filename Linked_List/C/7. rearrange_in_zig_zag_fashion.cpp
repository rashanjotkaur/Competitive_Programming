// https://practice.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

// Func 1
Node *zigZag(Node* head){
        if(head==NULL || head->next==NULL)
            return head;
        bool flag=true;
        Node *curr=head;
        while(curr->next){
            if(flag){
                if(curr->data>curr->next->data)
                    swap(curr,curr->next);
            }
            else{
                if(curr->data<curr->next->data)
                    swap(curr,curr->next);
            }
            flag=!flag;
            curr=curr->next;
        }
        return head;
}

// Func 2
void swap(Node* &a,Node* &b){
    int x=a->data;
    a->data=b->data;
    b->data=x;
}
    
