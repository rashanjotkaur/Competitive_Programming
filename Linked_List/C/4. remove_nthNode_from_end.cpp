// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        int total=0;
        ListNode *temp=head;
        while(temp){
            total++;
            temp=temp->next;
        }
        int s=total-n;
        if(s==0)
            return head->next;
        temp=head;
        s--;
        while(s>0){
            temp=temp->next;
            s--;
        }
        ListNode *delNode=temp->next;
        temp->next=temp->next->next;
        delete(delNode);
        return head;
}
