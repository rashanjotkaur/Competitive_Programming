// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Node* segregate(Node *head) {
        if(head==NULL)
            return NULL;
        int c0=0,c1=0,c2=0;
        Node *temp=head;
        while(temp){
            if(temp->data==0)
                c0++;
            else if(temp->data==1)
                c1++;
            else if(temp->data==2)
                c2++;
            temp=temp->next;
        }
        temp=head;
        while(c0--){
            temp->data=0;
            temp=temp->next;
        }
        while(c1--){
            temp->data=1;
            temp=temp->next;
        }
        while(c2--){
            temp->data=2;
            temp=temp->next;
        }
        return head;  
}
