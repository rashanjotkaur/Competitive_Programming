// https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1/

class Solution{
  public:
    Node *newNode(int x){
        Node *temp= new Node(x); //since, here Node(x) is already defined.
        return temp;
    }
  
    Node *insertAtBegining(Node *head, int x) {
        struct Node *temp=newNode(x);
        temp->next=head;
        head=temp;
        return head;
    }
    
    Node *insertAtEnd(Node *head, int x)  {
        if(head==NULL){
            head=newNode(x);
            return head;
        }
        struct Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode(x);
        return head;
    }
};
