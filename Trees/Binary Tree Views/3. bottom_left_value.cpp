// Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/description/

// Method 3: Using Recursion only - no extra space
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


// Method 2: Using Level Order Traversal
int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return -1;
        int res;
        queue <pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            res=q.front().first->val;
            while(size--){
                TreeNode *temp=q.front().first;
                int hd=q.front().second;
                q.pop();
                if(temp->left)
                    q.push({temp->left,hd-1});
                if(temp->right)
                    q.push({temp->right,hd+1});
            }
        }
        return res;
}


// Method 1: Using Vector and Recursion
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
