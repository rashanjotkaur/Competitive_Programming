//  https://leetcode.com/problems/merge-k-sorted-lists/description/

// Method 1 - Brute Force Solution 
// Comparing two lists -> Then merge them and compare it with the next one
// Time Complexity: O(nk^2)
// How Time Complexity is O(nk^2): 
// 1. Traversing all lists starting from the second list = n*k
// 2. Insert every node of the currently traversed list into result in a sorted way = k 
// Space Complexity: O(1)

// Func 1 - Merge K Linked Lists
ListNode* mergeKLists(vector <ListNode*> &lists) {
        ListNode *res=NULL;
        int k=lists.size();
        if(k==0)
            return res;
        if(k==1){
            res=lists[0];
            return res;
        }
        res=lists[0];
        for(int i=1;i<k;i++){
            ListNode *temp=lists[i];
            res=mergeLinkedList(res,temp);
        }
        return res;
}

// Func 2 - Merge 2 Linked Lists
ListNode* mergeLinkedList(ListNode* a, ListNode *b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode *res=NULL;
        if(a->val<b->val){
            res=a;
            res->next=mergeLinkedList(a->next,b);
        }
        else{
            res=b;
            res->next=mergeLinkedList(a,b->next);
        }
        return res;
}


// Method 2 - Using Priority Queue
// Time Complexity: O(k*nlogn)
// How the Time Complexity is O(knlogn)
// 1. Total K Linked Lists
// 2. Inserting each lists with 'n' number of nodes = nlogn

// Func 1:
ListNode* mergeKLists(vector <ListNode*> &lists) {
        int k=lists.size();
        if(k==0)
            return NULL;
        if(k==1)
            return lists[0];

        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++){
            ListNode *temp=lists[i];
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }

        ListNode *res=NULL;
        while(!pq.empty()){
            int x=pq.top();
            insert(res,x);
            pq.pop();
        }
        return res;
}

// Func 2: 
void insert(ListNode* &head, int x){
        if(head==NULL){
            head=newNode(x);
            return ;
        }
        ListNode *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=newNode(x);
}

// Func 3:
ListNode* newNode(int x){
        ListNode *temp=new ListNode;
        temp->val=x;
        temp->next=NULL;
        return temp;
}
    
    
    
    
