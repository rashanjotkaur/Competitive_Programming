// https://leetcode.com/problems/merge-k-sorted-lists/description/
// All Approaches: https://www.geeksforgeeks.org/cpp-program-to-merge-k-sorted-linked-lists-set-1/?ref=rp

// Best Method - Method 3

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
// Space Complexity: O(kn)

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
    
    


// Method 3 - DIVIDE & CONQUER - Preferred && Fastest Approached && No Extra Space required.
// 1. This approach doesn’t require extra space for heap and works in O(k*nlogn)
// 2. It is known that merging of two linked lists can be done in O(n)time and O(n) space. 
// 3. The idea is to pair up K lists and merge each pair in linear time using O(n) space.
// 4. After the first cycle, K/2 lists are left each of size 2*N. 
// 5. After the second cycle, K/4 lists are left each of size 4*N and so on.
// 6. Repeat the procedure until we have only one list left.

// Time Complexity: O(nk*logk)
// How is the Time Complexity O(nk*logk)?
// 1. Number of linked lists: k=8 -> 4 -> 2 -> 1
// 2. So, this is basically: log2(k)
// 3. Total Number of Elements we are traversing is: k*n
// 4. Hence, Time Complexity is O(k*n*logk)

// Func 1:
ListNode* mergeKLists(vector <ListNode*> &lists) {
        int k=lists.size();
        if(k==0)
            return NULL;
        if(k==1)
            return lists[0];

        int last=k-1;
        while(last!=0){
            int i=0,j=last;
            while(i<j){
                lists[i]=mergeSortedLL(lists[i], lists[j]);
                i++;
                j--;
                if(i>=j)
                    last=j;
            }
        }
        return lists[0];
}

// Func 2: 
ListNode* mergeSortedLL(ListNode *a, ListNode*b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode *res=NULL;
        if(a->val<b->val){
            res=a;
            res->next=mergeSortedLL(a->next,b);
        }
        else{
            res=b;
            res->next=mergeSortedLL(a,b->next);
        }
        return res;
}
    


    
