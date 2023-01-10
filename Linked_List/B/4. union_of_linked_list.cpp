// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1/#

// Method 1 - Using Set - O(m+n) space is used
Node* newNode(int x){
    Node *temp=new Node(x);
    return temp;
}
Node* insert(Node *head, int x){
    if(head==NULL){
        head=newNode(x);
        return head;
    }
    Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
    return head;
}
struct Node* makeUnion(struct Node* a, struct Node* b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    set <int> s;
    while(a){
        s.insert(a->data);
        a=a->next;
    }
    while(b){
        s.insert(b->data);
        b=b->next;
    }
    struct Node *res=NULL;
    for(auto it=s.begin();it!=s.end();it++)
        res=insert(res,*it);
        
    return res;
}


// Method 2 - O(1) Space
// Algorithm:
// 1. Sort linked list 'A' using merge sort: O(nlogn) 
// 2. Sort linked list 'B' using merge sort: O(mlogm) 
// 3. Remove the duplicates from each list while sorting the list.
// 4. Now, it is similar to merging two sorted lists without including duplicate elements

// Function - Main
struct Node* makeUnion(struct Node* a, struct Node* b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    mergeSort(a);
    mergeSort(b);
    
    return unionFun(a,b);
}

// Function - 1 - O(nlogn)
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
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node *res=NULL;
    if(a->data<b->data){
        res=a;
        res->next=mergeSortUtil(a->next,b);
    }
    else if(b->data<a->data){
        res=b;
        res->next=mergeSortUtil(a,b->next);
    }
    else{ // include only once, if present in both linked lists
        res=a;
        res->next=mergeSortUtil(a->next,b->next);
    }
    return res;
}

// Function - 4
Node* unionFun(Node *a, Node *b){
    Node *res=NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<b->data){
       res=a;
       res->next=unionFun(a->next,b);
    }
    else if(b->data<a->data){
        res=b;
        res->next=unionFun(a,b->next);
    }
    else{ // if equal
        res=a;
        res->next=unionFun(a->next,b->next);
    }
    return res;
}



// Method 3 - Here also we will sort the linked lists but will not remove the duplicates while sorting.
// We will remove the duplicates while adding into the linked lists.

// Func 1 - unionFun
struct Node* makeUnion(struct Node* a, struct Node* b){
    mergeSort(a);
    mergeSort(b);
    
    Node *res=newNode(0);
    Node *temp=res;
    while(a && b){
        if(a->data<b->data){
            if(temp->data!=a->data){
                temp->next=newNode(a->data);
                temp=temp->next;
            }
            a=a->next;
        }
        else if(b->data<a->data){
            if(temp->data!=b->data){
                temp->next=newNode(b->data);
                temp=temp->next;
            }
            b=b->next;
        }
        else if(a->data==b->data){
            if(temp->data!=a->data){
                temp->next=newNode(a->data);
                temp=temp->next;
            }
            a=a->next;
            b=b->next;
        }
    }
    while(a){
        if(temp->data!=a->data){
            temp->next=newNode(a->data);
            temp=temp->next;
        }
        a=a->next; 
    }
    while(b){
        if(temp->data!=b->data){
            temp->next=newNode(b->data);
            temp=temp->next;
        }
        b=b->next;
    }
    return res->next;
}

// Func 2 - mergeSort
Node* mergeSort(Node* &head){
    if(head==NULL || head->next==NULL)
        return head;
        
    Node *a=NULL;
    Node *b=NULL;
    split(head,a,b);
    
    mergeSort(a);
    mergeSort(b);
    
    head=merge(a,b);
    return head;
}

// Func 3 - split
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

// Func 4 - merge
Node* merge(Node *a, Node *b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node *res=NULL;
    if(a->data<b->data){
        res=a;
        res->next=merge(a->next,b);
    }
    else{
        res=b;
        res->next=merge(a,b->next);
    }
    return res;
}

// Func 5 - newNode 
Node* newNode(int x){
    Node *temp=new Node(x);
    temp->data=x;
    temp->next=NULL;
    return temp;
}
