// https://www.codingninjas.com/codestudio/problems/sort-biotonic-dll_981293?leftPanelTab=0
// https://www.geeksforgeeks.org/sort-biotonic-doubly-linked-list/

// Input 
// Testcases = 3
// n = 8
// 2 5 7 12 10 6 4 1
// n = 3
// 9 10 -1
// n = 3
// 4 3 -1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node* newNode(int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void printDLL(Node *head){
    while(head->next){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    cout<<endl;
    while(head){
        cout<<head->data<<" ";
        head=head->prev;
    }
    cout<<endl;
}

void insertDLL(Node *&head, int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
    temp->next->prev=temp;
}

Node* mergeSortedLL(Node *a, Node *b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node *res=NULL;
    while(a && b){
        if(a->data<b->data){
            insertDLL(res,a->data);
            a=a->next;
        }
        else{
            insertDLL(res,b->data);
            b=b->prev;
        }
    }
    while(a){
        insertDLL(res,a->data);
        a=a->next;
    }
    while(b){
        insertDLL(res,b->data);
        b=b->prev;
    }
    return res;
}

void endNode(Node *&head){
    if(head==NULL)
        return ;
    while(head->next)
        head=head->next;
}

void split(Node *head, Node* &a, Node* &b){
    Node *curr=head;
    Node *forw=head->next;
    while(curr && forw && curr->data<=forw->data){
        curr=curr->next;
        forw=forw->next;
    }
    a=head;
    if(curr)
        b=curr->next;
    curr->next=NULL;
    if(b)
        b->prev=NULL;
}

Node *sortDLL(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *a=NULL; // increasing linked list
    Node *b=NULL; // decreasing linked list
    split(head,a,b); 
    
    endNode(b); // get the end node of decreasing list
    
    Node *res=NULL;
    res=mergeSortedLL(a,b);
    return res;
}
  
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        Node *head=NULL;
        for(int i=0;i<n;i++){
            cin>>x;
            insertDLL(head,x);
        }
        Node *res=NULL;
        res=sortDLL(head);
        printDLL(res);
    }
    return 0;
}
