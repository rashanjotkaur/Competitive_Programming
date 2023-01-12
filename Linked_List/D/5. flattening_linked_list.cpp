// https://www.geeksforgeeks.org/flattening-a-linked-list/


// Method 1: Similar to the "Method 3 of Merging K Sorted Linked Lists".
// 1. Store each linked list in vector.
// 2. Then, use the same approach as we used for Merging K Sorted Linked Lists.
// Func 1 - flatten the linked lists.
Node *flatten(Node *root){
    if(root==NULL || root->next==NULL)
        return root;
    vector <Node*> lists;
    while(root){
        lists.push_back(root);
        root=root->next;
    }
    int k=lists.size();
    int last=k-1;
    while(last!=0){
        int i=0,j=last;
        while(i<j){
            lists[i]=mergeSortedLL(lists[i],lists[j]);
            i++;
            j--;
            if(i>=j)
                last=j;
        }
    }
    return lists[0];
}

// Func 2 - Merging the k sorted linked lists.
Node* mergeSortedLL(Node *a, Node*b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        Node *res=NULL;
        if(a->data<b->data){
            res=a;
            res->bottom=mergeSortedLL(a->bottom,b);
        }
        else{
            res=b;
            res->bottom=mergeSortedLL(a,b->bottom);
        }
        return res;
}



// Method 2: Traverse the linked lists and merge it with the next linked.
// No Extra Space Required.

// Func 1 - Since Every Node has Linked List associated with it.
Node *flatten(Node *root){
    if(root==NULL || root->next==NULL)
        return root;
        
    Node *res=NULL;
    while(root){
        res=mergeSortedLL(res,root);
        root=root->next;
    }
    return res;
}

// Func 2
Node* mergeSortedLL(Node *a, Node *b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        Node *res=NULL;
        if(a->data<b->data){
            res=a;
            res->bottom=mergeSortedLL(a->bottom,b);
        }
        else{
            res=b;
            res->bottom=mergeSortedLL(a,b->bottom);
        }
        return res;
}



// Method 3: Using Priority Queue
// Func 1: 
Node *flatten(Node *root){
    if(root==NULL || root->next==NULL)
        return root;
        
    priority_queue <int, vector<int>, greater<int>> pq;
    while(root){
        addInPQ(root,pq);
        root=root->next;
    }
    Node *res=NULL;
    while(!pq.empty()){
        insert(res,pq.top());
        pq.pop();
    }
    return res;
}

// Func 2: 
void addInPQ(Node *head, priority_queue <int, vector<int>, greater<int>> &pq){
    while(head){
        pq.push(head->data);
        head=head->bottom;
    }    
}

// Func 3:
void insert(Node* &head, int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    Node *temp=head;
    while(temp->bottom)
        temp=temp->bottom;
    temp->bottom=newNode(x);
}

Node* newNode(int x){
    Node *temp=new Node(x);
    temp->data=x;
    temp->next=NULL;
    temp->bottom=NULL;
    return temp;
}



