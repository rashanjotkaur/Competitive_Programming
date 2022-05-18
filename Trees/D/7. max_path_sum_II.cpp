// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int calPathSum(TreeNode* root, int &maxSum){
        if(root==NULL)
            return 0;
        
        int l=calPathSum(root->left,maxSum);
        int r=calPathSum(root->right,maxSum);
        
        maxSum=max({maxSum,root->val,l+root->val,r+root->val,l+r+root->val});
        return max({root->val,l+root->val,r+root->val});
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxSum=INT_MIN;
        calPathSum(root,maxSum);
        return maxSum;
    }
};



