// https://leetcode.com/problems/count-complete-tree-nodes/

// Method 1
int countNodes(Node* root){
    if(root==NULL)
         return 0;
    if(root->left==NULL && root->right==NULL)
         return 1;
    int count=1+countNodes(root->left)+countNodes(root->right);
         return count;
}

// Method 2 - Using Inorder
class Solution {
public:
    void countFun(struct TreeNode *root, int &count){
        if(root==NULL)
            return;
        
        countFun(root->left, count);
        count++;
        countFun(root->right, count);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int count=0;
        countFun(root,count);
        return count;
    }
};
