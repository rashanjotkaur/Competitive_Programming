// https://www.geeksforgeeks.org/sum-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node *arb;
};

Node* newNode(int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    temp->arb=NULL;
    return temp;
}

void print(Node *head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
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

void reverse(struct Node *&head){
    if(head==NULL && head->next==NULL)
        return ;
    Node *prev=NULL;
    Node *curr=head;
    Node *forw=NULL;
    
    while(curr){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
}

Node* addLinkedList(Node *head1, Node *head2){
    if(head1==NULL && head2==NULL)
        return NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    reverse(head1);
    reverse(head2);
    
    int x1=0,x2=0;
    int carry=0;
    Node *head=NULL;
    while(head1 || head2){
        if(head1){
            x1=head1->data;
            head1=head1->next;
        }
        if(head2){
            x2=head2->data;
            head2=head2->next;
        }
        int x=x1+x2+carry;
        int sum=x%10;
        carry=x/10;
        insert(head,sum);
        x1=0;
        x2=0;
    }
    if(carry)
        insert(head,carry);
    reverse(head);
    return head;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n1,n2,x;
	    cin>>n1;
	    struct Node *head1=NULL;
	    for(int i=0;i<n1;i++){
	        cin>>x;
	        insert(head1,x);
	    }
	    print(head1);
	    cin>>n2;
	    struct Node *head2=NULL;
	    for(int i=0;i<n2;i++){
	        cin>>x;
	        insert(head2,x);
	    }
	    print(head2);
	    Node *head=addLinkedList(head1,head2);
	    print(head);
	    cout<<endl;
	}
	return 0;
}
