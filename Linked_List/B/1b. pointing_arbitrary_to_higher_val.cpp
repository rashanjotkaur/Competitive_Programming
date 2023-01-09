// https://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/

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

void printNext(Node *head){
	cout<<"Traversal using Next Pointer "<<endl;
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void printArb(Node *arb_head){
    cout<<"Traversal using Arbitrary Pointer "<<endl;
	while(arb_head){
		cout<<arb_head->data<<" ";
		arb_head=arb_head->arb;
	}
	cout<<endl;
}

Node *merge(Node *a, Node *b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
        
    Node *res=NULL;
    if(a->data<b->data){
        res=a;
        res->arb=merge(a->arb,b);
    }
    else{
        res=b;
        res->arb=merge(a,b->arb);
    }
    return res;
}

void split(Node *head, Node *&a, Node *&b){
    Node *fast=head->arb;
    Node *slow=head;
    while(fast && fast->arb){
        fast=fast->arb->arb;
        slow=slow->arb;
    }
    a=head;
    b=slow->arb;
    slow->arb=NULL;
}

Node *mergeSort(Node *&head){
    // Forget about next pointer, consider "arb" as "next" pointer.
	if((head == NULL) || (head->arb == NULL))
		return head;

	Node *a=NULL;
	Node *b=NULL;
	split(head,a,b);

	mergeSort(a);
	mergeSort(b);

    head=merge(a,b);
    return head;
}

Node* populateArbit(Node *head){
	Node *temp = head;
	while(temp){
		temp->arb=temp->next;
		temp=temp->next;
	}
	// Do merge sort for arbitrary pointers
	head=mergeSort(head);

    // Return minimum value node as head of arbitrary pointer linked list
	return head;
}

int main(){
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
	    printNext(head);
	    Node *arb_head=populateArbit(head);
	    printArb(arb_head);
	    cout<<endl;
	}
	return 0;
}
