// https://practice.geeksforgeeks.org/problems/median-of-bst/1
void findNo(struct Node *root,int &count){
    if(root==NULL)
        return ;
    findNo(root->left,count);
    count++;
    findNo(root->right,count);
}
void median(Node *root,float &res1,float &res2,int n,int &k){
    if(root==NULL)
        return ;
    median(root->left,res1,res2,n,k);
    if(k==(n/2)-1)
        res1=root->data;
    if(k==n/2)
        res2=root->data;
    k++;
    median(root->right,res1,res2,n,k);
}
float findMedian(struct Node *root){
    int count=0;
    findNo(root,count);
    
    float res1,res2;
    int k=0;
    median(root,res1,res2,count,k);
    if(count%2==0)
        return (res1+res2)/2;
    else 
        return res2;
}
