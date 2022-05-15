// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/
// Method 1-O(n) space;
void traverse(struct Node *root,vector <int> &v){
    if(root==NULL)
        return ;
    traverse(root->left,v);
    v.push_back(root->data);
    traverse(root->right,v);
}
void inorder(struct Node *&root,vector <int> v,int &i){
    if(root==NULL)
        return ;
    inorder(root->left,v,i);
    root->data=v[i];
    i++;
    inorder(root->right,v,i);
}
struct Node *correctBST(struct Node* root){
    if(root==NULL)
        return root;
    vector <int> v;
    traverse(root,v);
    sort(v.begin(),v.end());
    int i=0;
    inorder(root,v,i);
    return root;
}

// Method 2-O(1) space;
void inorder(Node *root,Node *&first,Node *&mid,Node *&last,
    Node *&prev){
    if(root==NULL)
        return ;
    inorder(root->left,first,mid,last,prev);
    if(prev && root->data<prev->data){
        if(first==NULL){
            first=prev;
            mid=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right,first,mid,last,prev);
}
struct Node *correctBST( struct Node* root ){
    if(root==NULL)
        return root;
    struct Node *first=NULL,*mid=NULL,*last=NULL;
    struct Node *prev=NULL;
    inorder(root,first,mid,last,prev);
    if(first && last)
        swap(first->data,last->data);
    else if(first && mid)
        swap(first->data,mid->data);
    return root;
}
