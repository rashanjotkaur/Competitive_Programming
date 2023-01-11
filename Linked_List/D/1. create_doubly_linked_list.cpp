// https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
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
        printDLL(head);
    }
    return 0;
}
