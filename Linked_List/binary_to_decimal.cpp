// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// Method 1-Using extra space
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        stack <int> s;
        while(head){
            s.push(head->val);
            head=head->next;
        }
        int num=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            num=num+s.top()*pow(2,i);
            s.pop();
        }
        return num;   
    }
};


// Method 2-Without using extra space
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        int n=0;
        struct ListNode *temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        int num=0;
        int i=0;
        while(head){
            num=num+head->val*pow(2,n-1-i);
            head=head->next;
            i++;
        }
        return num;   
    }
};
