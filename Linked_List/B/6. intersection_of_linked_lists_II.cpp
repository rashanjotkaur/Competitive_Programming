// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1/#

class Solution{
  public:
    Node* newNode(int x){
        Node *temp=new Node(x);
        return temp;
    }
    Node* insert(Node *head, int x){
        if(head==NULL){
            head=newNode(x);
            return head;
        }
        Node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=newNode(x);
        return head;
    }
    Node* findIntersection(Node* a, Node* b){
        unordered_map <int,bool> ump;
        while(b){
            ump[b->data]=true;
            b=b->next;
        }
        Node *res=NULL;
        while(a){
            if(ump[a->data])
                res=insert(res,a->data);
            a=a->next;    
        }
        return res;
    }
};
