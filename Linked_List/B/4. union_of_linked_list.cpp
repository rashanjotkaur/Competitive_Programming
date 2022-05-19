// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1/#

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
