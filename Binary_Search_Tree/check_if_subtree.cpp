void search(struct Node *root,int x,vector <struct Node*> &v){
    if(root==NULL)
        return ;
    if(root->data==x){
        v.push_back(root);
    }
    search(root->left,x,v);
    search(root->right,x,v);
}
bool traverse(struct Node *temp,struct Node *sub){
    if(temp==NULL && sub==NULL)
        return true;
    if(temp==NULL || sub==NULL)
        return false;
    if(temp->data!=sub->data)
        return false;
    bool l=traverse(temp->left,sub->left);
    bool r=traverse(temp->right,sub->right);
    return l & r;
}
bool isSubTree(Node* root, Node* sub) {
    if(root==NULL || sub==NULL)
        return false;
        
    vector <struct Node*> v;
    search(root,sub->data,v);
    if(v.size()==0)
        return false;
    for(int i=0;i<v.size();i++){
        struct Node *temp=v[i];
        bool ans=traverse(temp,sub);
        if(ans)
            return true;
    }
    return false;
    
}
