// Answer will be in the sorted form as we are using merge sort

// Steps:
// 1. Sort the both linked lists -> sort head1 && sort head2 using merge sort
// 2. Then use the interesection function.

// Input
// Testcases: 2
// n1=5
// 1 2 3 6 4
// n2=3
// 8 4 6
// n1=4
// 10 20 40 50
// n2=2
// 15 40

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* newNode(int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

void insert(Node *&head,int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
}

void print(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* intersection(Node *head1,Node *head2){
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

void split(Node *head, Node* &a, Node* &b){
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
  
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2,x;
        cin>>n1;
        Node *head1=NULL;
        for(int i=0;i<n1;i++){
            cin>>x;
            insert(head1,x);
        }
        cin>>n2;
        Node *head2=NULL;
        for(int i=0;i<n2;i++){
            cin>>x;
            insert(head2,x);
        }
        mergeSort(head1);
        print(head1);
        mergeSort(head2);
        print(head2);
        Node *head=NULL;
        head=intersection(head1,head2);
        print(head);
    }
    return 0;
}


// Intersection Method - Using Recursion
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
