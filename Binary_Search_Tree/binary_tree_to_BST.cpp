void traversal(struct Node *root,vector <int> &vec){
    if(root==NULL)
        return ;
    traversal(root->left,vec);
    vec.push_back(root->data);
    traversal(root->right,vec);
}
void inorder(struct Node *&root,vector <int> vec,int &i){
    if(root==NULL)
        return ;
    inorder(root->left,vec,i);
    root->data=vec[i];
    i++;
    inorder(root->right,vec,i);
}
Node *binaryTreeToBST (Node *root){
    if(root==NULL)
        return root;
    vector <int> vec;
    traversal(root,vec);
    sort(vec.begin(),vec.end());
    int i=0;
    inorder(root,vec,i);
    return root;
}
