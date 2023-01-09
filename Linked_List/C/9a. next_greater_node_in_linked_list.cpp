// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

// Func 1 
vector <int> nextLargerNodes(ListNode* head) {
        vector <int> res;
        if(head==NULL)
            return res;
        reverseList(head);
        stack <int> s;
        ListNode* temp=head;
        while(temp){
            while(!s.empty() && s.top()<=temp->val)
                s.pop();
            
            if(s.empty())
                res.push_back(0);
            else
                res.push_back(s.top());

            s.push(temp->val);
            temp=temp->next;
        }
        reverse(res.begin(),res.end());
        return res;
}

// Func 2
void reverseList(ListNode* &head){
        if(head==NULL)
            return ;
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forw=NULL;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        head=prev;
}
    
