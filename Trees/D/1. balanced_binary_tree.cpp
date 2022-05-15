// https://leetcode.com/problems/balanced-binary-tree/

// Method 1: Using bool variable -> ans
// Function - Main
bool isBalanced(TreeNode* root) {
        bool ans=true;
        check_func(root,ans);
        return ans;
}
// Function - 1
int check_func(struct TreeNode *root,bool &ans){
        if(root==NULL)
            return 0;
        int l=check_func(root->left,ans);
        int r=check_func(root->right,ans);
        if(abs(l-r)>1)
            ans=false;
        return max(l,r)+1;
}


// Method 2:
// Function - Main
bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh=height(root->left);
        int lr=height(root->right);
        if(abs(lh-lr)>1)
            return false;
        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);
        return l & r;
}
// Function - 1
int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
}
