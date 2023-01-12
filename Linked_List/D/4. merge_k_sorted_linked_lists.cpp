//  https://leetcode.com/problems/merge-k-sorted-lists/description/

// Method 1 - Brute Force Solution 
// Comparing two lists -> Then merge them and compare it with the next one

// Func 1 - Merge K Linked Lists
ListNode* mergeKLists(vector <ListNode*> &lists) {
        ListNode *res=NULL;
        int n=lists.size();
        if(n==0)
            return res;
        if(n==1){
            res=lists[0];
            return res;
        }
        res=lists[0];
        for(int i=1;i<n;i++){
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
    
