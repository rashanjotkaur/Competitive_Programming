// https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    void swapFun(TreeNode* root){
        if(root==NULL)
            return ;
        swap(root->left,root->right);
        swapFun(root->left);
        swapFun(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        swapFun(root);
        return root;
    }
};
