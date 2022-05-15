// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/
int findceil(struct Node *root,int k){
    struct Node *curr=root;
    int val=-1;
    while(curr){
        if(curr->data>k){
            val=curr->data;
            curr=curr->left;
        }
        else if(curr->data==k){
            val=k;
            break;
        }
        else
            curr=curr->right;
    }
    if(val==-1)
        return -1;
    return val;
}
int findfloor(struct Node *root,int k){
    struct Node *curr=root;
    int val=-1;
    while(curr){
        if(curr->data<k){
            val=curr->data;
            curr=curr->right;
        }
        else if(curr->data==k){
            val=curr->data;
            break;
        }
        else
            curr=curr->left;
    }
    if(val==-1)
        return -1;
    return val;
}
int minDiff(Node *root, int k){
    if(root==NULL)
        return 0;
    int greater=findceil(root,k);
    int smaller=findfloor(root,k);
    int d1=INT_MAX,d2=INT_MAX;
    if(greater!=-1)
        d1=abs(greater-k);
    if(smaller!=-1)
        d2=abs(k-smaller);
    if(d1==INT_MAX && d2==INT_MAX)
        return 0;
    return min(d1,d2);
}
