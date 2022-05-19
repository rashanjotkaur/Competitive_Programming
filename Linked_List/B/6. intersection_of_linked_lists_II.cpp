// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1/#

class Solution{
  public:
    Node* newNode(int x){
        Node *temp=new Node(x);
        return temp;
    }
    Node* findIntersection(Node* a, Node* b){
        unordered_map <int,bool> ump;
        while(b){
            ump[b->data]=true;
            b=b->next;
        }
        Node *res=NULL;
        Node *temp=NULL;
        while(a){
            if(ump[a->data]){
                if(res==NULL){
                    res=newNode(a->data);
                    temp=res;
                }
                else{
                    temp->next=newNode(a->data);
                    temp=temp->next;
                }
            }
            a=a->next;    
        }
        return res;
    }
};
