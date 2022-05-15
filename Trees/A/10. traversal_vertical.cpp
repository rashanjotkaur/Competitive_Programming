// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Method 1-The below solution uses preorder traversal and Hashmap to store nodes according to horizontal distances. 
// Since above approach uses preorder traversal, nodes in a vertical line may not be prined in same order as they appear in tree.
// Hence, we use vd, to check the level of node, so that they appear in the same manner as they are in the tree.
class Solution {
public:
    void verticalTraversalFun(TreeNode *root,int hd,int vd,map <int,vector<pair<int,int>>> &mp){
        if(root==NULL)
            return ;
        mp[hd].push_back({vd,root->val});
        verticalTraversalFun(root->left,hd-1,vd+1,mp);
        verticalTraversalFun(root->right,hd+1,vd+1,mp);
    }
    vector <vector<int>> verticalTraversal(TreeNode* root) {
        map <int,vector<pair<int,int>>> mp;
        int hd=0,vd=0;
        verticalTraversalFun(root,hd,vd,mp);
        vector <vector<int>> res;
        for(auto x:mp){
            vector <pair<int,int>> temp=x.second;
            sort(temp.begin(),temp.end());
            vector <int> row;
            for(int i=0;i<temp.size();i++)
                row.push_back(temp[i].second);
            res.push_back(row);
        }
        return res;
    }
};


// Method 2-Level Order Traversal using queue
class Solution {
public:
    vector <vector<int>> verticalTraversal(TreeNode* root) {
        vector <vector<int>> res;
        if(root==NULL)
            return res;
        map <int,vector<pair<int,int>>> mp;
        int hd=0,vd=0;
        queue <pair<struct TreeNode*,pair<int,int>>> q;
        q.push({root,{hd,vd}});
        while(!q.empty()){
            struct TreeNode *temp=q.front().first;
            hd=q.front().second.first;
            vd=q.front().second.second;
            q.pop();
            mp[hd].push_back({vd,temp->val});
            if(temp->left)
                q.push({temp->left,{hd-1,vd+1}});
            if(temp->right)
                q.push({temp->right,{hd+1,vd+1}});
        }
        for(auto x:mp){
            vector <pair<int,int>> temp=x.second;
            sort(temp.begin(),temp.end());
            vector <int> row;
            for(int i=0;i<temp.size();i++)
                row.push_back(temp[i].second);
            res.push_back(row);
        }
        return res;
    }
};
