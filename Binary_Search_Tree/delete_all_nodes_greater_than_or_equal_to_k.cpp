struct Node *FindMin(struct Node *root){
    if(root==NULL)
        return root;
    struct Node *temp=root;
    while(temp && temp->left)
        temp=temp->left;
    return temp;
}
Node* deleteNode(Node* root, int key){
    if(root==NULL)
        return root;
    root->left=deleteNode(root->left,key);
    root->right=deleteNode(root->right,key);
    if(root->data>=key){
        // Case 1: No child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        // Case 2: Only one child
        else if(root->left && root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left==NULL && root->right){
            struct Node *temp=root;
            root=root->right;
            delete temp;
        }
        // Case 3: Two children
        else if(root->left && root->right){
            struct Node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }
    return root;
}
