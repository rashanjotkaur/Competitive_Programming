// Similar to "Next Greater Element in Stack in Circular Array"

// Description: Given singly linked list with every node having an additional “arbitrary” pointer that currently points to NULL. 
//              Need to make the “arbitrary” pointer point to the next higher value node.

// Input: 
// Testcases: 3

// T1:
// n=4
// Linked List: 4 -2 5 8
// Output: 5 5 8 -1 

// T2: 
// n=4
// Linked List: 5 10 2 3
// Output: 10 -1 3 5 

// T3: 
// n=4
// Linked List: 3 2 10 5
// Output: 10 10 -1 10 


// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *arb;
};

Node* newNode(int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    temp->arb=NULL;
    return temp;
}

void insert(struct Node* &head, int x){
    if(head==NULL){
        head=newNode(x);
        return ;
    }
    struct Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
    return ;
}

void printList(struct Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseList(struct Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *forw=NULL;
    while(curr){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
    return head;
} 

void nextGreaterPointers(struct Node* head){
    if(head==NULL || head->next==NULL)
        return ;
    
    Node *rhead=reverseList(head);
    cout<<"Reverse Linked List:"<<endl;
    printList(rhead);
    
    stack <Node*> s;
    Node *temp=rhead;
    while(temp){
        s.push(temp);
        temp=temp->next;
    }
    
    temp=rhead;
    while(temp){
        while(!s.empty() && s.top()->data<=temp->data)
            s.pop();
        if(!s.empty() && s.top()->data>temp->data){
            temp->arb=s.top();
            s.push(temp);
        }
        else
            s.push(temp);
        temp=temp->next;
    }
    
    head=reverseList(rhead);
    cout<<"Linked List:"<<endl;
    printList(head);
    
    temp=head;
    cout<<"Arb Pointers: "<<endl;
    while(temp){
        if(temp->arb)
            cout<<temp->arb->data<<" ";
        else
            cout<<"-1"<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n;
	    struct Node *head=NULL;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        insert(head,x);
	    }
	    nextGreaterPointers(head);
	    cout<<endl;
	}
	return 0;
}
