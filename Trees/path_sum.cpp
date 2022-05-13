// https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool checkPath(TreeNode* root, int targetSum){  
        if(targetSum-root->val==0 && root->left==NULL && root->right==NULL)
            return true;
        
        bool ans=false;
        if(root->left)
            ans=ans || checkPath(root->left,targetSum-root->val);
        if(root->right)
            ans=ans || checkPath(root->right,targetSum-root->val);
        return ans;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        return checkPath(root, targetSum);
    }
};
