// https://practice.geeksforgeeks.org/problems/children-sum-parent/1

// Method 1 - Good One
class Solution{
    public:
    bool isSumFun(Node *root){
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;

        int l=0,r=0;
        if(root->left)
            l=root->left->data;
        if(root->right)
            r=root->right->data;
        if(root->data!=l+r)
            return false;
        bool left=isSumFun(root->left);
        bool right=isSumFun(root->right);
        return left & right;
    }
    int isSumProperty(Node *root){
        if(root==NULL)
            return 1;
        return isSumFun(root);
    }
};


// Method 2 - Passing bool variable - ans
class Solution{
    public:
    void isSumFun(Node *root, bool &ans){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
            return ;
        int l=0,r=0;
        if(root->left)
            l=root->left->data;
        if(root->right)
            r=root->right->data;
        if(root->data!=l+r){
            ans=false;
            return ;
        }
        isSumFun(root->left,ans);
        isSumFun(root->right,ans);
    }
    int isSumProperty(Node *root){
        if(root==NULL)
            return 1;
        bool ans=true;
        isSumFun(root,ans);
        return ans;
    }
};


// Method 3 - Little difficult to think
// Function - Main
int isSumProperty(Node *root){
    if(root==NULL || isLeaf(root))
        return 1;
    int l,r;
    if(isSumProperty(root->left) && isSumProperty(root->right)){
        if(root->left==NULL)
            l=0;
        else
            l=root->left->data;

        if(root->right==NULL)
            r=0;
        else
            r=root->right->data;

        return root->data==l+r ? 1 : 0;
    }
    return 0;
}
// Function - 1
bool isLeaf(struct Node *root){
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}
