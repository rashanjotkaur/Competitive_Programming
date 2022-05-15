// https://leetcode.com/problems/cousins-in-binary-tree/

// Method 1 - Recursion
class Solution {
public:
    void cousinsFun(TreeNode* root,int x,int y,unordered_map <int,pair<int,int>> &ump, int level){
        if(root==NULL)
            return ;
        if(root->left){
            if(root->left->val==x || root->left->val==y)
                ump[root->left->val]={level+1,root->val};
        }
        if(root->right){
            if(root->right->val==x || root->right->val==y)
                ump[root->right->val]={level+1,root->val};
        }
        cousinsFun(root->left,x,y,ump,level+1);
        cousinsFun(root->right,x,y,ump,level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        if(root->val==x || root->val==y)
            return false;
        unordered_map <int,pair<int,int>> ump;
        cousinsFun(root,x,y,ump,1);
        if((ump[x].first==ump[y].first) && (ump[x].second!=ump[y].second))
            return true;
        return false;
    }
};


// Method 2 - Using Level Order Traversal
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        if(root->val==x || root->val==y)
            return false;
        queue <pair<TreeNode*,int>> q;
        unordered_map <int,pair<int,int>> ump;
        q.push({root,-1});
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                struct TreeNode *temp=q.front().first;
                int parent=q.front().second;
                q.pop();
                if(temp->val==x || temp->val==y)
                    ump[temp->val]={level,parent};
                
                if(temp->left)
                    q.push({temp->left,temp->val});
                if(temp->right)
                    q.push({temp->right,temp->val});
            }
            level++;
        }
        if(ump[x].first==ump[y].first && ump[x].second!=ump[y].second)
            return true;
        return false;
    }
};
