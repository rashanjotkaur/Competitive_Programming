// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        if(root==p || root==q)
            return root;
        
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        if(l && r)
            return root;
        return l?l:r;
    }
};
