struct Node* newNode(int key){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
// BST doesn't contain duplicate nodes
Node* insert(Node* root, int key){
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    return root;
}
