// https://leetcode.com/problems/find-bottom-left-tree-value/

// Method 1 - Recursion without using any extra space - Easy
class Solution {
public:
    void findBottomLeft(TreeNode *root, int level,int &maxLevel,int &ans){
        if(root==NULL)
            return ;
        if(maxLevel<level){
            ans=root->val;
            maxLevel=level;
        }
        findBottomLeft(root->left,level+1,maxLevel,ans);
        findBottomLeft(root->right,level+1,maxLevel,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxLevel=-1;
        int ans;
        findBottomLeft(root,0,maxLevel,ans);
        return ans;
    }
};



// Method 2 - Using Vector - Faster than Method 3 - Easy Also
class Solution {
public:
    void findBottomLeft(TreeNode *root, int level,vector <int> &vec){
        if(root==NULL)
            return ;
        if(level==vec.size())
            vec.push_back(root->val);
        
        findBottomLeft(root->left,level+1,vec);
        findBottomLeft(root->right,level+1,vec);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector <int> vec;
        findBottomLeft(root,0,vec);
        return vec.back();
    }
};



// Method 3 - Without using any extra space (Slow) - Complex
class Solution {
public:
    void findBottomLeft(TreeNode* root,int vd,int &maxDepth,int hd,int &maxHori,int &ans){
        if(root==NULL)
            return ;
        if(maxDepth<vd){
            ans=root->val;
            maxDepth=vd;
            maxHori=hd;
        }
        else if(maxDepth==vd){
            if(maxHori>hd){
                maxHori=hd;
                ans=root->val;
            }
        }
        findBottomLeft(root->left,vd+1,maxDepth,hd-1,maxHori,ans);
        findBottomLeft(root->right,vd+1,maxDepth,hd+1,maxHori,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxDepth=0;
        int maxHori=0;
        int ans=root->val;
        findBottomLeft(root,0,maxDepth,0,maxHori,ans);
        return ans;
    }
};

