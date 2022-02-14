void traversal(struct Node *root,int currLen,int &res){
    if(root==NULL)
        return ;
        
    currLen++;    
    if(currLen>1 && currLen>res)
        res=currLen;
        
    if(root->left && root->data+1==root->left->data)
        traversal(root->left,currLen,res);
    else
        traversal(root->left,0,res);
    
    if(root->right && root->data+1==root->right->data)    
        traversal(root->right,currLen,res);
    else
        traversal(root->right,0,res);
}
int longestConsecutive(Node* root){
    if(root==NULL)
        return -1;
    int res=-1;
    traversal(root,0,res);
    return res;
}
