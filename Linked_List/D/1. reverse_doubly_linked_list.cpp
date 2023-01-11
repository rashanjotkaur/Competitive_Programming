// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Node* reverseDLL(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *temp=NULL;
    while(head->next){
        temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        head=temp;
    }
    head->next=head->prev;
    head->prev=NULL;
    return head;
}
