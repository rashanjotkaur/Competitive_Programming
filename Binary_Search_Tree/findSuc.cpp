void findSuc(struct Node *root,int x,struct Node* &suc){
    if(root==NULL)
        return;
    if(root->data==x){
        if(root->right!=NULL){
            struct Node *temp=root->right;
            while(temp->left)
                temp=temp->left;
            suc=temp;
        }
    }
    if(x<root->data){
        suc=root;
        findSuc(root->left,x,suc);
    }
    else
        findSuc(root->right,x,suc);
}
Node * inOrderSuccessor(Node *root, Node *target){
    if(root==NULL)
        return root;
    struct Node *suc=NULL;
    findSuc(root,target->data,suc);
    return suc;
}
