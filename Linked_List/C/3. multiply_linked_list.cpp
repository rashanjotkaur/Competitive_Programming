// https://www.geeksforgeeks.org/multiply-two-numbers-represented-linked-lists/

#define mod 1000000007

long long  multiplyTwoLists (Node* l1, Node* l2){
    if(l1==NULL || l2==NULL)
        return 0;
    long long x1=0,x2=0;
    while(l1){
        int d=l1->data;
        x1=x1*10;
        x1=x1+d;
        x1=x1%mod;
        l1=l1->next;
    }
    while(l2){
        int d=l2->data;
        x2=x2*10;
        x2=x2+d;
        x2=x2%mod;
        l2=l2->next;
    }
    return (x2*x1)%mod;
}
