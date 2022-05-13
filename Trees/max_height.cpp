// https://leetcode.com/problems/maximum-depth-of-binary-tree/

public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        // return lh>rh?lh+1:rh+1;
        return max(lh,rh)+1;
    }
};
