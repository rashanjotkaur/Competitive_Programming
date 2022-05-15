// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    // edges=nodes-1
    int height(TreeNode* root, int &maxDia){
        if(root==NULL)
            return 0;
        int lh=height(root->left,maxDia);
        int rh=height(root->right,maxDia);
        maxDia=max(maxDia,lh+rh+1);  //maximum nodes in the path
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;

        int maxDia=INT_MIN;
        height(root,maxDia);
        return maxDia-1;  //maximum edges in the path
    }
};
