// Bottom View of Binary Tree
// Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

vector <int> bottomView(Node *root) {
        vector <int> res;
        if(root==NULL)
            return res;
        
        map <int,int> mp;
        queue <pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp=q.front().first;
            int hd=q.front().second;
            q.pop();
            mp[hd]=temp->data;
            if(temp->left)
                q.push({temp->left,hd-1});
            if(temp->right)
                q.push({temp->right,hd+1});
        }
        
        for(auto x:mp)
            res.push_back(x.second);
        return res;
}
