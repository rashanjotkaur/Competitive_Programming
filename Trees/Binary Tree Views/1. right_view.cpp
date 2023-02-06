// Right View of Binary Tree
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// https://leetcode.com/problems/binary-tree-right-side-view/

// Method 2: Using Recursion
void rightView(TreeNode *root, int level, int &maxLevel, vector <int> &res){
        if(root==NULL)
            return ;
        if(maxLevel<level){
            maxLevel=level;
            res.push_back(root->val);
        }
        rightView(root->right,level+1,maxLevel,res);
        rightView(root->left,level+1,maxLevel,res);
}
vector <int> rightSideView(TreeNode* root) {
        vector <int> res;
        if(root==NULL)
            return res;
        int maxLevel=-1;
        rightView(root,0,maxLevel,res);
        return res;
}


// Method 1: Level Order Traversal
vector <int> rightSideView(TreeNode* root) {
        vector <int> res;
        if(root==NULL)
            return res;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(size==1)
                    res.push_back(temp->val);
                size--;
            }
        }
        return res;
}
