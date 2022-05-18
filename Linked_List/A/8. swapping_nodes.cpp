// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        cout<<n<<endl;
        
        int l=n-k;
        ListNode *start=head;
        k--;
        while(k--)
            start=start->next;
        cout<<start->val<<endl;
        
        ListNode *end=head;
        while(l--)
            end=end->next;
        cout<<end->val<<endl;
        
        swap(start->val,end->val);
        return head;
    }
};
