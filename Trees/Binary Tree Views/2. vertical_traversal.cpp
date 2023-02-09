// Vertical order traversal of Binary Tree
// Problem Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

vector <int> verticalOrder(Node *root){
        vector <int> res;
        if(root==NULL)
            return res;
        map <int,vector<int>> mp;
        queue <pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp=q.front().first;
            int hd=q.front().second;
            mp[hd].push_back(temp->data);
            q.pop();
            if(temp->left)
                q.push({temp->left,hd-1});
            if(temp->right)
                q.push({temp->right,hd+1});
        }
        for(auto x:mp){
            vector <int> temp=x.second;
            for(auto y:temp)
                res.push_back(y);
        }
        return res;
}
