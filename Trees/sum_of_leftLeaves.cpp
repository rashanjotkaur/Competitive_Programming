// 

// Method 1
class Solution {
public:
    void sumLeftNodes(TreeNode *root,bool left,bool right,int &sum){
        if(root==NULL)
            return ;
        if(left && root->left==NULL && root->right==NULL){
            sum=sum+root->val;
            return ;
        }
        sumLeftNodes(root->left,true,false,sum);
        sumLeftNodes(root->right,false,true,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        bool left=false,right=false;
        sumLeftNodes(root,left,right,sum);
        return sum;
    }
};

// Method 2 - Same as above but remove (bool right), as not required
public:
    void sumLeftNodes(TreeNode *root,bool isLeft,int &sum){
        if(root==NULL)
            return ;
        if(isLeft && root->left==NULL && root->right==NULL){
            sum=sum+root->val;
            return ;
        }
        sumLeftNodes(root->left,true,sum);
        sumLeftNodes(root->right,false,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        bool isLeft=false;
        sumLeftNodes(root,isLeft,sum);
        return sum;
    }
};
