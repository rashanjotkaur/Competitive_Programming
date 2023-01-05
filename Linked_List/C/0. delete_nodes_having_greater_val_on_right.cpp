// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    Node *compute(Node *head){
        if(head==NULL)
            return NULL;
        Node *temp=head;
        while(temp && temp->next){
            if(temp->data<temp->next->data){
                temp->data=temp->next->data;
                Node *curr=temp->next;
                temp->next=temp->next->next;
                delete(curr);
                temp=head;
            }
            else
                temp=temp->next;
        }
        return head;
    }
};
