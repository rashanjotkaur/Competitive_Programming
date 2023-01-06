// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// Method 1 - Using Hashmap
void removeLoop(Node* head){
        if(head==NULL)
            return ;
        unordered_map <Node*,int> ump;
        Node *temp=head;
        Node *prev=NULL;
        bool loop=false;
        while(temp){
            if(ump[temp]){
                loop=true;
                break;
            }
            else{
                ump[temp]=true;
                prev=temp;
                temp=temp->next;
            }
        }
        if(loop)
            prev->next=NULL;
}


// Method 2 - Using Set
void removeLoop(Node* head){
        if(head==NULL)
            return ;
        unordered_set <Node*> s;
        Node *temp=head;
        Node *prev=NULL;
        bool loop=false;
        while(temp){
            if(s.find(temp)!=s.end()){
                loop=true;
                break;
            }
            else{
                s.insert(temp);
                prev=temp;
                temp=temp->next;
            }
        }
        if(loop)
            prev->next=NULL;
}
