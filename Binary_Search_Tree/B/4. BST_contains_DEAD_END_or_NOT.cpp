// Method 1-O(n) space
unordered_map <int,bool> ump;
vector <int> v;
void traversal(struct Node *root){
    if(root==NULL)
        return ;
    if(root->left==NULL && root->right==NULL)
        v.push_back(root->data);
    ump[root->data]=true;
    traversal(root->left);
    traversal(root->right);
}
bool isDeadEnd(Node *root){
    if(root==NULL)
        return false;
    traversal(root);
    ump[0]=true;
    for(int i=0;i<v.size();i++){
        int x=v[i];
        if(ump[x+1] && ump[x-1])
            return true;
    }
    return  false;
}

// Method 2-O(1)
bool traverse(struct Node *root,int mini,int maxi){
    if(root==NULL)
        return false;
    if(mini==maxi)
        return true;
    bool l=traverse(root->left,mini,root->data-1);
    bool r=traverse(root->right,root->data+1,maxi);
    return l || r;
}
bool isDeadEnd(Node *root){
    if(root==NULL)
        return false;
    int mini=1,maxi=INT_MAX;
    return traverse(root,mini,maxi);
}
