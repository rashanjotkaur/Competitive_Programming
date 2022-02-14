void inorder(struct Node *root,int &res,int &k){
    if(root==NULL)
        return ;
    inorder(root->left,res,k);
    if(k==1)
        res=root->data;
    k--;
    inorder(root->right,res,k);
}
int KthSmallestElement(Node *root, int k){
    int res=-1;
    inorder(root,res,k);
    return res;
}
