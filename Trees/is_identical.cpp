// https://leetcode.com/problems/same-tree/

// Method 1 - Faster
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q) || (p && q==NULL))
            return false;
        
        bool ans=false;
        if(p->val==q->val)
            ans=true;
        
        ans=ans & isSameTree(p->left,q->left);
        ans=ans & isSameTree(p->right,q->right);
        return ans;
    }
};

// Method 2
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q) || (p && q==NULL))
            return false;
        if(p->val!=q->val)
            return false;
        
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);
        return l & r;
    }
};
