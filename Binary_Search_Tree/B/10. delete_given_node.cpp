struct Node *FindMin(struct Node *root){
    struct Node *temp=root;
    while(temp && temp->left)
        temp=temp->left;
    return temp;
}
Node *deleteNode(Node *root,int x){
    if(root==NULL)
        return root;
    if(x<root->data)
        root->left=deleteNode(root->left,x);
    else if(x>root->data)
        root->right=deleteNode(root->right,x);
    else{
        // Case1: No Child
        if(root->left==NULL && root->right==NULL){
            // free(root);
            delete root;
            root=NULL;
            // return root;
        }
        // Case2 : only one child
        else if(root->left==NULL && root->right){
            struct Node *temp=root;
            root=root->right;
            // free(temp);
            delete temp;
            // return root;
        }
        else if(root->right==NULL && root->left){
            struct Node *temp=root;
            root=root->left;
            // free(temp);
            delete temp;
            // return root;
        }
        // Case3 : both children
        else if(root->left && root->right){
            struct Node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            // return root;
        }
    }
    return root;
    
}
