// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

class Solution{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head) {
        unordered_set <int> s;
        Node *curr=head;
        Node *prev=NULL;
        while(curr){
            if(s.find(curr->data)!=s.end()){
                Node *temp=curr;
                prev->next=curr->next;
                delete(temp);
                curr=prev->next;
            }
            else{
                s.insert(curr->data);
                prev=curr;
                curr=prev->next;
            }
        }
        return head;
    }
};
