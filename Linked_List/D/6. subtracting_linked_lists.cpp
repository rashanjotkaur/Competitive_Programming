 // https://www.geeksforgeeks.org/subtract-two-numbers-represented-as-linked-lists/

// Func 1:
Node* subLinkedList(Node* l1, Node* l2){
    if(l1==NULL && l2==NULL)
        return NULL;
        
    int n1=countNodes(l1);
    int n2=countNodes(l2);
    
    Node *lar=NULL;
    Node *small=NULL;
    
    if(n1!=n2){
        lar=n1>n2?l1:l2;
        small=n1<n2?l1:l2;
        int diff=abs(n1-n2);
        addZeroes(small,diff);
        l1=lar;
        l2=small;
    }
    
    Node *temp1=l1;
    Node *temp2=l2;
    while(temp1 && temp2 && temp1->data==temp2->data){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1 && temp2){
        lar=temp1->data>temp2->data?l1:l2;
        small=temp1->data<temp2->data?l1:l2;
    }
    if(temp1==NULL && temp2==NULL)
        return newNode(0);
    
    l1=reverse(lar);
    l2=reverse(small);
    
    Node *l=NULL;
    int overhead=0;
    while(l1 && l2){
        int x1=l1->data+overhead;
        int x2=l2->data;
        if(x1<x2){
            x1=x1+10;
            overhead=-1;
        }
        else
            overhead=0;
        int x=x1-x2;
        insertAtBeg(l,x);
        x1=0;
        x2=0;
        l1=l1->next;
        l2=l2->next;
    }
    while(l && l->data==0)
        l=l->next;
    if(l==NULL){
        l=newNode(0);
        return l;
    }
    return l;
}

// Func 2:
int countNodes(Node *head){
    int n=0;
    Node *temp=head;
    while(temp){
        n++;
        temp=temp->next;
    }
    return n;
}

// Func 3: 
void addZeroes(Node *&head,int d){
    while(d--){
        Node *temp=head;
        head=newNode(0);
        head->next=temp;
    }
}

// Func 4: 
void insertAtBeg(Node *&head, int x){
    if(head==NULL){
        head=newNode(x);
        return; 
    }
    Node *temp=head;
    head=newNode(x);
    head->next=temp;
}

void print(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node *newNode(int x){
    Node *temp=new Node(x);
    temp->data=x;
    temp->next=NULL;
    return temp;
}

