void findPreSuc(Node* root, Node*& pre, Node*& suc, int x){
    if(root==NULL)
        return ;
    if(root->key==x){
        if(root->left!=NULL){
            struct Node *temp=root->left;
            while(temp->right)
                temp=temp->right;
            pre=temp;
        }
        if(root->right!=NULL){
            struct Node *temp=root->right;
            while(temp->left)
                temp=temp->left;
            suc=temp;
        }
        return ;
    }
    if(x<root->key){
        suc=root;
        findPreSuc(root->left,pre,suc,x);
    }
    else if(x>root->key){
        pre=root;
        findPreSuc(root->right,pre,suc,x);
    }
}
