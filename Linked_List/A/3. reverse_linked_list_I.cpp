// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

// Input: 1 2 3 4 5
// Output: 3 2 1 5 4
// Method 1 - Without using extra space
class Solution{
    public:
    struct node *reverse(struct node *head, int k){ 
        if(head==NULL)
            return head;
        
        struct node *curr=head;
        struct node *next=NULL;
        struct node *prev=NULL;
        
        int i=0;
        while(curr && i<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        
        if(next)
            head->next=reverse(next,k);
        
        return prev;
    }
};


// Method 2 - Using Stack
class Solution{
    public:
        struct node *reverse(struct node *head, int k){ 
            stack <struct node*> s; 
            
            struct node *curr = head;
            struct node *prev = NULL;
            struct node *next = NULL;
         
            while (curr != NULL){
                int i = 0;
                while (curr != NULL && i < k){
                    s.push(curr);
                    curr = curr->next;
                    i++;
                }
         
                while (s.size() > 0){
                    if (prev == NULL){
                        prev = s.top();
                        head = prev;
                        s.pop();
                    }
                    else{
                        prev->next = s.top();
                        prev = prev->next;
                        s.pop();
                    }
                }
            }
         
            prev->next = NULL;
            return head;
        }
};
