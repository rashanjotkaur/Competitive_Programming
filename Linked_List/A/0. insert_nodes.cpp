#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node* newNode(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}

void insert(Node *&head, int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=newNode(x);
}

void print(Node* head){
	while(head){
	    cout<<head->data<<" ";
	    head=head->next;
	}
	cout<<endl;
}

int main(){
    int n,k,x;
    cin>>n>>k;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(head,x);
    }	
    print(head);
    return 0;
}
