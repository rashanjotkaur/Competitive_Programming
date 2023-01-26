// https://practice.geeksforgeeks.org/problems/sum-tree/1#

// Method 2-BEST APPROACH
// Func 1:
bool isSumTree(Node* root){
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;

        int ls = sum(root->left);
        int rs = sum(root->right);
        
        return ((root->data==ls+rs) && isSumTree(root->left) && isSumTree(root->right));
}
// Func 2:
int sum(struct Node *root){
        if(root == NULL)
            return 0;
         
        return sum(root->left) + root->data + sum(root->right);
}
    

// OR


// Why l=2*(root->left->data)?
// If the node is not a leaf node then the sum of the subtree rooted with this node is twice the value of this node 
// (Assuming that the tree rooted with this node is SumTree).
bool isLeaf(struct Node *root){
    if(root==NULL)  return false;
    if(root->left==NULL && root->right==NULL)   return true;
    return false;
}
bool isSumTree(Node* root){
    int l,r;
    if(root==NULL || isLeaf(root))
        return true;
    if(isSumTree(root->left) && isSumTree(root->right)){
        if(root->left==NULL)
            l=0;
        else if(isLeaf(root->left))
            l=root->left->data;
        else 
            l=2*(root->left->data);

        if(root->right==NULL)
            r=0;
        else if(isLeaf(root->right))
            r=root->right->data;
        else 
            r=2*(root->right->data);

        return root->data==l+r ? true : false;
    }
    return false;
}


// Method 1;
int sum(struct Node *root,bool &ans){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int l=sum(root->left,ans);
    int r=sum(root->right,ans);
    if(l+r!=root->data)
        ans=false;
    return l+r+root->data;
}
bool isSumTree(Node* root){
     bool ans=true;
     sum(root,ans);
     return ans;
}


