// https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1/#

// Similar to Reverse the Linked List Question 

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

Node *newNode(int key){
	Node *temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}

int countPallindrome(Node *a, Node *b){
    int count=0;
    while(a && b){
        if(a->data!=b->data)
            break;
        count++;
        a=a->next;
        b=b->next;
    }
    return count;
}

int maxPalindrome(Node *head){
    if(head==NULL)
        return 0;
    int maxLen=0;
    Node *curr=head;
    Node *prev=NULL;
    Node *next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
    
        // Odd Pallindrome
        int oddLen = 2*countPallindrome(prev,next)+1;
        // Even Pallindrome
        int evenLen = 2*countPallindrome(curr,next);
        
        maxLen = max({maxLen,oddLen,evenLen});
        
        prev=curr;
        curr=next;
    }
    return maxLen;
}

Node *insert(Node *head, int x){
    if(head==NULL){
        head=newNode(x);
        return head;
    }
    struct Node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode(x);
    return head;
}

void print(Node *head){
    struct Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        struct Node *head=NULL;
        int x,n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            head=insert(head,x);
        }
        // print(head);
        cout<<maxPalindrome(head)<<endl;
    }
	return 0;
}

// Input
// 1
// 7
// 2 3 7 3 2 12 24
