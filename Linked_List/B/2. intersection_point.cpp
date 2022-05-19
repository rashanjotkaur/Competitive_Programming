// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    int count(ListNode *head){
        if(head==NULL)
            return 0;
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        if(a==NULL || b==NULL)
            return NULL;
        
        int countA=count(a);
        int countB=count(b);
        int diff=abs(countA-countB);
        
        ListNode *tempA=a;
        ListNode *tempB=b;
        
        if(countA>countB){
            while(diff--)
                tempA=tempA->next;
        }
        else{
            while(diff--)
                tempB=tempB->next;
        }
        while(tempA && tempB){
            if(tempA==tempB)
                return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};
