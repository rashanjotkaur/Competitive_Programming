// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
    void calGoodNodes(TreeNode *root,int maxNode,int &count){
        if(root==NULL)
            return ;
        if(root->val>=maxNode){
            count++;
            maxNode=root->val;
            // cout<<count<<" "<<maxNode<<endl;
        }
        calGoodNodes(root->left,maxNode,count);
        calGoodNodes(root->right,maxNode,count);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxNode=INT_MIN;
        int count=0;
        calGoodNodes(root,maxNode,count);
        return count;
    }
};
