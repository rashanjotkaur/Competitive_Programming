// Answer will be in the sorted form as we are using merge sort


// Main Function
Node* findIntersection(Node* a, Node* b){
        if(a==NULL)
            return a;
        if(b==NULL)
            return b;
        
        mergeSort(a);
        mergeSort(b);
        
        return intersection(a,b);
}

// Function - 1
Node* mergeSort(Node *&head){
        if(head==NULL || head->next==NULL)
            return head;
        
        Node *a=NULL;
        Node *b=NULL;
        split(head,a,b);
        
        mergeSort(a);
        mergeSort(b);
        head=mergeSortUtil(a,b);
        return head;
}

// Function - 2
void split(Node *head, Node *&a, Node *&b){
        Node *slow=head;
        Node *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        a=head;
        b=slow->next;
        slow->next=NULL;
}

// Function - 3
Node* mergeSortUtil(Node *a, Node *b){
        Node *res=NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->data<b->data){
            res=a;
            res->next=mergeSortUtil(a->next,b);
        }
        else if(a->data>b->data){
            res=b;
            res->next=mergeSortUtil(a,b->next);
        }
        else{  // if equal
            res=a;
            res->next=mergeSortUtil(a->next,b->next);
        }
        return res;
}

// Function - 4

Node *intersection(Node *a,Node *b){
        if(a==NULL || b==NULL)
            return NULL;
        Node *res=NULL;
        if(a->data<b->data)
            res=intersection(a->next,b);
        else if(b->data<a->data)
            res=intersection(a,b->next);
        else if(a->data==b->data){
            res=a;
            res->next=intersection(a->next,b->next);
        }
        return res;
}
